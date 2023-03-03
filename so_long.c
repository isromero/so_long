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

/*typedef struct s_rect
{
	int	x;
	int	y;
	int width;
	int height;
	int color;
}	t_rect;*/

void    read_map(char *filename, t_data *data)
{
    t_map **map;
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
    data->map = map;
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

//tal vez deba cambiar esta función de validar ya que el return ; hace q con encontrarse uno ya no muestra si no es valido en otros
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
            printf("Not valid walls on the left\n");
            return ;
        }
        if (map[y][number_col - 1].type != '1')
        {
            printf("Not valid walls on the right\n");
            return ;
        }
        y++;
    }
    while(x < number_col)
    {
        if (map[0][x].type != '1' || map[number_line - 1][x].type != '1')
        {
            printf("Not valid walls on the top or/and bottom\n");
            return ;
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
    if (found_c == true && found_e == true && found_p == true)
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

void    rectangle(t_img *img, int x1, int y1, int x2, int y2, t_data *data)
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
}

void clear_background(int color, t_data *data)
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

void draw(t_data *data)
{
	int x;
    int y;

    x = 0;
    y = 0;
    
    while(y < data->map_height)
    {
		x = 0;
        while(x < data->map_width)
        {
			if(data->map == WALL) 
            {
                mlx_pixel_put(data->mlx_ptr, data->win_ptr, x * 32, y * 32, RED_PIXEL);
            }
            x++;
        }
        y++;
    }
}

int render(t_data *data)
{
    //render no funciona si modifico datos de las estructuras como data o img... con mlx_put_image_to_window

    //utilizo data e img como argumentos ya que al pasarlos como variables locales de la función al acceder a ellas a través de un puntro daría seg fault.
    clear_background(WHITE_PIXEL, data);
    //rectangle(img, 100, 100, 200, 200, data); //prueba rectangulo
	draw(data);
    
	return(0);
}

int main(int argc, char **argv)
{
    
    t_data   data; //si solo necesitas leer los datos dentro de la función, puedes pasar la estructura sin utilizar un puntero. Pero si necesitas modificar los datos dentro de la función, es necesario pasar la estructura a través de un puntero
    t_img   img;
    read_map(argv[1], &data);
    int width = 0;
    width = data.map_width * 32;
    int height = 0;
    height = data.map_height * 32;
    printf("window width : %d\n", width);
    printf("Window height : %d\n", height);

    data.mlx_ptr = mlx_init();
    data.win_ptr = mlx_new_window(data.mlx_ptr, width, height, "so_long");

    //movements
    mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data); //espera a recibir un evento
    mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data); //2 = KeyPress, 1<<0= KeyPressMask
    mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, &data); //3 = KeyRelease, 1L<<1 KeyReleaseMask

    //drawing
    img.mlx_img = mlx_new_image(data.mlx_ptr, width, height); //crea una imagen en la memoria de video de la pantalla
    img.addr = mlx_get_data_addr(img.mlx_img, &img.bpp, &img.line_len, &img.endian); //se devuelve un puntero al primer byte de la imagen donde se usa para escribir en ella pixel por pixel
	//printf("bpp: %d, line_len, %d, endian: %d\n", img.bpp, img.line_len, img.endian);
    mlx_loop_hook(data.mlx_ptr, &render, &data);
    mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, img.mlx_img, 0, 0); //ponemos la imagen en pantalla
    mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);


    mlx_loop(data.mlx_ptr);

    mlx_destroy_image(data.mlx_ptr, img.mlx_img);
    mlx_destroy_display(data.mlx_ptr);
    free(data.mlx_ptr);
    return (0);
}

//me he quedado con las dimensiones de la pantalla, creo que deben
//ser ajustadas a la pantalla dependiendo el tamaño del mapa
//pero al asignar el tamaño del mapa para crear la ventana(imagen)
//ni siquiera se abre la nueva ventana

//quiero conseguir q pinte el muro por ahora  solo da seg fault