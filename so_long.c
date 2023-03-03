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
/*typedef struct s_rect
{
	int	x;
	int	y;
	int width;
	int height;
	int color;
}	t_rect;*/

//tal vez deba cambiar esta función de validar ya que el return ; hace q con encontrarse uno ya no muestra si no es valido en otros
void    validating_walls(t_data *data, t_map **map)
{
    int     x;
    int     y;

    x = 0;
    y = 0;
    while(y < data->map_height) 
    {
        if (map[y][0].type != '1')
        {
            printf("Not valid walls on the left\n");
            return ;
        }
        if (map[y][data->map_width - 1].type != '1')
        {
            printf("Not valid walls on the right\n");
            return ;
        }
        y++;
    }
    while(x < data->map_width)
    {
        if (map[0][x].type != '1' || map[data->map_height - 1][x].type != '1')
        {
            printf("Not valid walls on the top or/and bottom\n");
            return ;
        }
        x++;
    }
    printf("Valid walls...\n");
}

void validating_chars(t_data *data, t_map **map)
{
    int x, y;
    bool found_c = false, found_e = false, found_p = false;

    x = 0;
    y = 0;
    // Recorrer el mapa para encontrar C, E, y P
    while (y < data->map_height) 
    {
        x = 0;
        while (x < data->map_width) 
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
    if (found_c == true && found_e == true && found_p == true)
        printf("Valid chars...\n");
    if (found_c != true && found_e != true && found_p != true)
        printf("Doesn't have 'C', 'E', 'P'\n");
}

void    parse_objects(t_data *data, t_map **map)
{
    int x, y;

    x = 0;
    y = 0;
    // Recorrer el mapa para encontrar C, E, y P
    while (y < data->map_height) 
    {
        x = 0;
        while (x < data->map_width) 
        {
            if (map[y][x].type == '0')
            {
                map[y][x].type = EXIT;
                printf("%c", '0');
                return ;
            }
            else if (map[y][x].type == '1')
            {
                map[y][x].type = WALL;
                printf("%c", '1');
                return ;
            }
            else if (map[y][x].type == 'C')
            {
                map[y][x].type = COLLECTABLE;
                printf("%c", 'C');
                return ;
            }
            else if (map[y][x].type == 'E')
            {
                map[y][x].type = EXIT;
                printf("%c", 'E');
                return ;
            }
            else if (map[y][x].type == 'P')
            {
                map[y][x].type = INITIAL_POSITION;
                printf("%c", 'P');
                return ;
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
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		exit (1);
	}
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

void clear_background(int color, t_data *data, t_map **map)
{
    int width;
    int height;
    width = 0;
    height = 0;

    width = data->map_width * 32;
    height = data->map_height * 32;
    int x;
    int y;

    x = 0;
    y = 0;
    
    //printf ("%c\n", map[1][1].type);
    while(y < height)
    {
        x = 0;
        while(x < width)
        {
            mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, color);
            x++;
        }
        y++;
    }
}

void draw(t_data *data, t_map **map, t_img *img)
{
    int width;
    int height;
    width = 0;
    height = 0;

    width = data->map_width * 32;
    height = data->map_height * 32;
	int x;
    int y;

    x = 0;
    y = 0;

    //printf ("%c\n", map[1][1].type);
    while(y < height)
    {
        x = 0;
        while(x < width)
        {
            if(map[y][x].type == WALL)
            {
                mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, RED_PIXEL); //probar texturas
                mlx_put_image_to_window (data->mlx_ptr, data->win_ptr, img->mlx_img, x * 32, y * 32);
            }
            x++;
        }
        y++;
    }
}

int render(t_data *data)
{
    t_map   **map;
    t_img   *img;
    //render no funciona si modifico datos de las estructuras como data o img... con mlx_put_image_to_window

    //utilizo data e img como argumentos ya que al pasarlos como variables locales de la función al acceder a ellas a través de un puntro daría seg fault.
    //clear_background(WHITE_PIXEL, data, map);
    //rectangle(img, 100, 100, 200, 200, data); //prueba rectangulo
	draw(data, map, img);

	return(0);
}

void    creating_window(t_data *data, t_img *img, t_map **map)
{
    int width = 0;
    width = data->map_width * 32;
    int height = 0;
    height = data->map_height * 32;
    printf("window width : %d\n", width);
    printf("Window height : %d\n", height);

    data->mlx_ptr = mlx_init();
    data->win_ptr = mlx_new_window(data->mlx_ptr, width, height, "so_long");

    //movements
    mlx_loop_hook(data->mlx_ptr, &handle_no_event, &data); //espera a recibir un evento
    mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data); //2 = KeyPress, 1<<0= KeyPressMask
    mlx_hook(data->win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, &data); //3 = KeyRelease, 1L<<1 KeyReleaseMask

    //drawing
    img->mlx_img = mlx_new_image(data->mlx_ptr, width, height); //crea una imagen en la memoria de video de la pantalla
    img->addr = mlx_get_data_addr(img->mlx_img, &img->bpp, &img->line_len, &img->endian); //se devuelve un puntero al primer byte de la imagen donde se usa para escribir en ella pixel por pixel
	//printf("bpp: %d, line_len, %d, endian: %d\n", img->bpp, img->line_len, img->endian);
    printf ("map real: %c\n", map[1][1].type);
    //mlx_loop_hook(data->mlx_ptr, &render, data);
    //clear_background(WHITE_PIXEL, data);
    //mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->mlx_img, 0, 0); //ponemos la imagen en pantalla
    mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);


    mlx_loop(data->mlx_ptr);

    mlx_destroy_image(data->mlx_ptr, img->mlx_img);
    mlx_destroy_display(data->mlx_ptr);
    free(data->mlx_ptr);
}

void    so_long(t_data *data, t_img *img, t_map **map)
{
    validating_walls(data, map);
    validating_chars(data, map);
    parse_objects(data, map);
    creating_window(data, img, map);
}

void just_read_and_info(char *filename, t_data *data, t_img *img, t_map **map)
{
    int    fd;
    char    *line;
    int   number_line;
    int   number_col;
    int     y;

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
		data->map_width = number_col;
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
	data->map_height = number_line;
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
    printf ("just read: %c\n", map[1][1].type);
    so_long(data, img, map);
}

/*void    rectangle(t_img *img, int x1, int y1, int x2, int y2, t_data *data)
{

    for (int x = x1; x <= x2; x++)
    {
        mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y1, RED_PIXEL);
    }

    // Dibujar línea inferior
    for (int x = x1; x <= x2; x++)
    {
        mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y2, RED_PIXEL);
    }

    // Dibujar línea izquierda
    for (int y = y1; y <= y2; y++)
    {
        mlx_pixel_put(data->mlx_ptr, data->win_ptr, x1, y, RED_PIXEL);
    }

    // Dibujar línea derecha
    for (int y = y1; y <= y2; y++)
    {
        mlx_pixel_put(data->mlx_ptr, data->win_ptr, x2, y, RED_PIXEL);
    }
}*/

int main(int argc, char **argv)
{
    t_data  data;
    t_img   img;
    t_map  *map;
    just_read_and_info(argv[1], &data, &img, &map);
    return (0);
}

//me he quedado con las dimensiones de la pantalla, creo que deben
//ser ajustadas a la pantalla dependiendo el tamaño del mapa
//pero al asignar el tamaño del mapa para crear la ventana(imagen)
//ni siquiera se abre la nueva ventana

//quiero conseguir q pinte el muro por ahora  solo da seg fault