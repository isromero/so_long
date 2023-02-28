/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 12:27:41 by marvin            #+#    #+#             */
/*   Updated: 2023/02/17 12:27:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

void    validating_chars(t_map **map, size_t number_line, size_t number_col);
void    validating_walls(t_map **map, size_t number_line, size_t number_col);
void    parse_objects(t_map **map, size_t number_line, size_t number_col);

void    read_map(char *filename)
{
    t_map **map;
    size_t     fd;
    char    *line;
    size_t  number_line;
    size_t  number_col;
    size_t     y;

    line = NULL;
    number_line = 0;
    y = 0;
    fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        printf("Error al abrir el archivo\n");
    }

    // Contamos el número de líneas en el archivo
    while ((line = get_next_line(fd)) != NULL)
    {
        number_col = strlen(line);
        number_line++;
        free(line);
    }

    //Alojamos memoria 
    map = malloc(number_line * sizeof(t_map *)); // Con esto alojamos a map[y][x] 
    while(y < number_line)
    {
        map[y] = malloc(number_col * sizeof(t_map));
        memset(map[y], 0, number_col * sizeof(t_map));
        y++;
    }
    close (fd);
    fd = open(filename, O_RDONLY);

    y = 0;
    while(((line = get_next_line(fd))) != NULL) //Se seguirá ejecutando hasta que termine el archivo ya que gnl devuelve todo el rato una línea hasta el final
    {
        for (int x = 0; x < number_col; x++) 
        {
            map[y][x].type = line[x];
        }
        free(line);
        y++;
    }
    close(fd);
    validating_walls(map, number_line, number_col);
    validating_chars(map, number_line, number_col);
    parse_objects(map, number_line, number_col);
}

void    validating_walls(t_map **map, size_t number_line, size_t number_col)
{
    size_t     x;
    size_t     y;

    x = 0;
    y = 0;
    while(y < number_line) 
    {
        if (map[y][0].type != '1')
        {
            printf("Not walls on the left\n");
            break ;
        }
        if (map[y][number_col - 1].type != '1')
        {
            printf("Not walls on the right\n");
            break ;
        }
        y++;
    }
    while(x < number_col)
    {
        if (map[0][x].type != '1' || map[number_line - 1][x].type != '1')
        {
            printf("Not walls on the top/bottom\n");
            break ;
        }
        x++;
    }
    printf("Valid walls...\n");
}

void validating_chars(t_map **map, size_t number_line, size_t number_col) 
{
    size_t x, y;
    bool found_c = false, found_e = false, found_p = false;

    x = 0;
    y = 0;
    // Recorrer el mapa para encontrar C, E, y P
    while (y < number_line) 
    {
        x = 0;
        while (x < number_col) 
        {
            if (map[y][x].type == 'C') 
                found_c = true;
            else if (map[y][x].type == 'E')
                found_e = true;
            else if (map[y][x].type == 'P')
                found_p = true;
            x++;
        }
        y++;
    }
    // Comprobar si se encontraron todas las letras
    if (found_c && found_e && found_p)
        printf("Valid chars...\n");
    if (found_c != true && found_e != true && found_p != true)
        printf("Doesn't have 'C', 'E', 'P'\n");
}

void    parse_objects(t_map **map, size_t number_line, size_t number_col)
{
    size_t x, y;

    x = 0;
    y = 0;
    // Recorrer el mapa para encontrar C, E, y P
    while (y < number_line) 
    {
        x = 0;
        while (x < number_col) 
        {
            if (map[y][x].type == '0')
            {
                map[y][x].type = EXIT;
                printf("%c", '0');
            }
            else if (map[y][x].type == '1')
            {
                map[y][x].type = WALL;
                printf("%c", '1');
            }
            else if (map[y][x].type == 'C')
            {
                map[y][x].type = COLLECTABLE;
                printf("%c", 'C');
            }
            else if (map[y][x].type == 'E')
            {
                map[y][x].type = EXIT;
                printf("%c", 'E');
            }
            else if (map[y][x].type == 'P')
            {
                map[y][x].type = INITIAL_POSITION;
                printf("%c", 'P');
            }
            x++;
        }
        y++;
        printf("\n");
    }
}

int	handle_keyrelease(int key, t_data *data)
{
    if (key == 'W')
        data->y = 0;
    if (key == 'A')
        data->x = 0;
    if (key == 'S')
        data->y = 0;
    if (key == 'D')
        data->x = 0;
    return (0);
}

int	handle_keypress(int key, t_data *data)
{
    if (key == XK_Escape)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
    if (key == 'W')
        data->y--;
    if (key == 'A')
        data->x--;
    if (key == 'S')
        data->y++;
    if (key == 'D')
        data->x++;
    return (0);
}

int handle_no_event(t_data *data)
{
    return (0);
}

int clear_background(t_img *img, int color)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while(y < 600)
    {
        while(x < 800)
        {
            mlx_pixel_put(data.mlx_ptr, data.win_ptr, x, y, color);
            x++;
        }
        y++;
    }
}

int render_rect(t_img *img, t_rect rect)
{
	int	i;
	int j;

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			img_pix_put(img, j++, i, rect.color);
		++i;
	}
	return (0);
}

int render(t_data *data)
{
    clear_background(data->img, WHITE_PIXEL);
    render_rect(&data->img, (t_rect){WINDOW_WIDTH - 100, WINDOW_HEIGHT - 100, 100, 100, GREEN_PIXEL});
	render_rect(&data->img, (t_rect){0, 0, 100, 100, RED_PIXEL});

    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0); //ponemos la imagen en pantalla
    return (0);
}

int main(int argc, char **argv)
{
    read_map(argv[1]);
    t_data   data; //si solo necesitas leer los datos dentro de la función, puedes pasar la estructura sin utilizar un puntero. Pero si necesitas modificar los datos dentro de la función, es necesario pasar la estructura a través de un puntero

    data.mlx_ptr = mlx_init();
    data.win_ptr = mlx_new_window(data.mlx_ptr, 800, 600, "so_long");

    //movements
    mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data); //espera a recibir un evento
    mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
    mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, &data);

    //drawing
    data.img.mlx_img = mlx_new_image(data.mlx_ptr, 800, 600); //crea una imagen en la memoria de video de la pantalla
    data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp,
			&data.img.line_len, &data.img.endian); //se devuelve un puntero al primer byte de la imagen donde se usa para escribir en ella pixel por pixel
    mlx_loop_hook(data.mlx_ptr, &render, &data);
    mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);

    mlx_loop(data.mlx_ptr);
    return (0);
}