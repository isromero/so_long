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


void init_img(t_img *img)
{
    img->mlx_img = NULL;
    img->img_width = 0;
    img->img_height = 0;
}

void init_struct(t_data *data)
{
    data->mlx_ptr = 0;
    data->win_ptr = 0;
    data-> current_img = 0;
   	data->map = 0;
    data->x = 0;
    data->y = 0;
    data->player_x = 0;
    data->player_y = 0;
	data->player_mov = 0;
	data->map_width = 0;
    data->map_height = 0;
}

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
                map[y][x].type = EMPTY;
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
void    ft_empty(t_data *data, t_img *img)
{
    img->mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./img/empty.xpm", &img->img_width, &img->img_height);
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->mlx_img, data->x * 32, data->y * 32);
}

void    ft_wall(t_data *data, t_img *img)
{
    img->mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./img/wall.xpm", &img->img_width, &img->img_height);
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->mlx_img, data->x * 32, data->y * 32);
}

void    ft_collectable(t_data *data, t_img *img)
{
    img->mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./img/collectable.xpm", &img->img_width, &img->img_height);
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->mlx_img, data->x * 32, data->y * 32);
}

void    ft_exit(t_data *data, t_img *img)
{
    img->mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./img/exit.xpm", &img->img_width, &img->img_height);
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->mlx_img, data->x * 32, data->y * 32);
}

void    ft_initial(t_data *data, t_img *img)
{
    img->mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./img/initial.xpm", &img->img_width, &img->img_height);
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->mlx_img, data->x * 32, data->y * 32);
}


void draw(t_data *data, t_img *img)
{
    // t_img   **objs;
    // objs = malloc(sizeof(t_img *) * 5);
    // objs[EMPTY] = malloc(sizeof(t_img));
    // objs[WALL] = malloc(sizeof(t_img));
    // objs[COLLECTABLE] = malloc(sizeof(t_img));
    // objs[EXIT] = malloc(sizeof(t_img));
    // objs[INITIAL_POSITION] = malloc(sizeof(t_img));

    // objs[EMPTY]->mlx_img = 
    // objs[WALL]->mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./img/wall.xpm", &objs[WALL]->img_width, &objs[WALL]->img_height);
    // objs[COLLECTABLE]->mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./img/collectable.xpm", &objs[COLLECTABLE]->img_width, &objs[COLLECTABLE]->img_height);
    // objs[EXIT]->mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./img/exit.xpm", &objs[EXIT]->img_width, &objs[EXIT]->img_height);
    // objs[INITIAL_POSITION]->mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./img/initial.xpm", &objs[INITIAL_POSITION]->img_width, &objs[INITIAL_POSITION]->img_height);

    //objs = malloc(sizeof(t_img *));
    //printf ("%c\n", map[1][1].type);
    while(data->y < data->map_height)
    {
        data->x = 0;
        while(data->x < data->map_width)
        {
            if (data->map[data->y][data->x] == '0')
            {
                ft_empty(data, img);
                printf("%c",'0');
            }
            if (data->map[data->y][data->x] == '1')
            {
                ft_wall(data, img);
                printf("%c",'1');
            }
            if (data->map[data->y][data->x] == 'C')
            {
                ft_collectable(data, img);
                printf("%c",'C');
            }
            if (data->map[data->y][data->x] == 'E')
            {
                ft_exit(data, img);
                printf("%c",'E');
            }
            if (data->map[data->y][data->x] == 'P')
            {
                data->player_y = data->y;
                data->player_x = data->x;
                ft_initial(data, img);
                printf("%c",'P');
            }
            data->x++;
        }
        data->y++;
        printf("\n");
    }
}

void	move_up(t_data *data, t_img *img)
{
	data->map[data->player_y][data->player_x] = '0';
	data->map[data->player_y - 1][data->player_x] = 'P';
	//data->player_mov++;
    data->player_y--;
	draw(data, img);
 }

int	handle_keypress(int key, t_data *data, t_img *img)
{
    if (data->player_x < 0 || data->player_x >= data->map_height || data->player_y < 0 || data->player_y >= data->map_width)
        printf("Error: las coordenadas del jugador están fuera de los límites del mapa\n");
    if (!data)
        printf("Error: data es un puntero nulo\n");
    if (!data->map)
        printf("Error: data->map es un puntero nulo\n");
    if (key == XK_Escape) //XK_Escape, 59
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		exit (1);
	}
    if (key == 119) //probando solo W
    {
		//printf("antes: x=%d, y=%d\n", data->x, data->y);
		move_up(data, img);
        printf("Después: x=%d, y=%d\n", data->player_x, data->player_y);
    }
    // if (key == 97 && data->map[data->player_y - 1][data->player_x] != '1' && data->map[data->player_y - 1][data->player_x] != 'E')
    //     data->player_x--;
    // if (key == 115 && data->map[data->player_y - 1][data->player_x] != '1' && data->map[data->player_y - 1][data->player_x] != 'E')
    //     data->player_y++;
    // if (key == 100 && data->map[data->player_y - 1][data->player_x] != '1' && data->map[data->player_y - 1][data->player_x] != 'E')
    //     data->player_x++;
    return (0);
}

int	handle_keyrelease(int key, t_data *data, t_img *img, t_map **map)
{
    // if (key == 119)
    // {
    //     data->y = 0;
    // }
    // if (key == 97)
    //     data->x = 0;
    // if (key == 115)
    //     data->y = 0;
    // if (key == 100)
    //     data->x = 0;
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




int render(t_data *data, t_img *img)
{
    //render no funciona si modifico datos de las estructuras como data o img... con mlx_put_image_to_window

    //utilizo data e img como argumentos ya que al pasarlos como variables locales de la función al acceder a ellas a través de un puntro daría seg fault.
    //clear_background(WHITE_PIXEL, data, map);
    //rectangle(img, 100, 100, 200, 200, data); //prueba rectangulo
	draw(data, img);

	return(0);
}



void    creating_window(t_data *data, t_img *img)
{
    int width = 0;
    width = data->map_width * 32;
    int height = 0;
    height = data->map_height * 32;
    data->mlx_ptr = mlx_init();
    data->win_ptr = mlx_new_window(data->mlx_ptr, width, height, "so_long");

    

    //drawing
    img->mlx_img = mlx_new_image(data->mlx_ptr, width, height); //crea una imagen en la memoria de video de la pantalla
    img->addr = mlx_get_data_addr(img->mlx_img, &img->bpp, &img->line_len, &img->endian); //se devuelve un puntero al primer byte de la imagen donde se usa para escribir en ella pixel por pixel
    //clear_background(WHITE_PIXEL, data, map);
    
    draw(data, img);
    //mlx_loop_hook(data->mlx_ptr, &render, &data);
    


    //movements
	
    //mlx_loop_hook(data->mlx_ptr, &handle_no_event, data); //espera a recibir un evento
    mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &handle_keypress, data); //2 = KeyPress, 1<<0= KeyPressMask
    //mlx_hook(data->win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, data); //3 = KeyRelease, 1L<<1 KeyReleaseMask
	
	
	//mlx_hook(data->win_ptr, 2, 1<<0, &handle_keypress, &data);


    mlx_loop(data->mlx_ptr);

    //mlx_destroy_image(data->mlx_ptr, img->mlx_img);
    //mlx_destroy_display(data->mlx_ptr);
    //free(data->mlx_ptr);
}

void    so_long(t_data *data, t_img *img)
{
    // validating_walls(data, map);
    // validating_chars(data, map);
    //parse_objects(data, map);
    creating_window(data, img);
}

void just_read_and_info(char *filename, t_data *data, t_img *img)
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
    data->map = malloc(number_line * sizeof(char *)); // Con esto alojamos a map[y][x] 
    while(y < number_line)
    {
        data->map[y] = malloc(number_col * sizeof(char));
        memset(data->map[y], 0, number_col * sizeof(char));
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
            data->map[y][x] = line[x];
        }
        free(line);
        y++;
    }
    close(fd);
    so_long(data, img);
}

int main(int argc, char **argv)
{
    t_data  data;

    t_img   img;
    init_struct(&data);
    just_read_and_info(argv[1], &data, &img);
    return (0);
}

// https://medium.com/@benjaminmerchin/42-black-hole-deep-dive-cbc4b343c6b2