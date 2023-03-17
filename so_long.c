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
    img->mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./img/walls.xpm", &img->img_width, &img->img_height);
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->mlx_img, data->x * 32, data->y * 32);
}

void    ft_collectable(t_data *data, t_img *img)
{
    img->mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./img/collectable.xpm", &img->img_width, &img->img_height);
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->mlx_img, data->x * 32, data->y * 32);
}

void    ft_exit(t_data *data, t_img *img)
{
    img->mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./img/exit_closed.xpm", &img->img_width, &img->img_height);
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->mlx_img, data->x * 32, data->y * 32);
}


static char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static size_t	number_len(int nb)
{
	size_t	len;

	len = 0;
	if (nb <= 0)
		len++;
	while (nb)
	{
		len++;
		nb = nb / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*s;
	size_t	len;

	len = number_len(n);
	s = (char *)malloc(sizeof(char) * (len + 1));
	if (!s)
		return (0);
	if (n == -2147483648)
		return (ft_strcpy(s, "-2147483648"));
	if (n < 0)
	{
		s[0] = '-';
		n *= -1;
	}
	if (n == 0)
		s[0] = '0';
	s[len--] = '\0';
	while (n)
	{
		s[len--] = n % 10 + '0';
		n = n / 10;
	}
	return (s);
}

void	ft_mov_display(t_data *data, t_img *img)
{
	mlx_string_put(data->mlx_ptr, data->win_ptr,
		data->map_width *32 * 0.6, 10, 0xff0000,
		"Movements: ");
    mlx_string_put(data->mlx_ptr, data->win_ptr,
		data->map_width *32 * 0.9, 10, 0xff0000,
		ft_itoa(data->player_mov));
}

void    ft_initial(int key, t_data *data, t_img *img)
{
    img->mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./img/initial.xpm", &img->img_width, &img->img_height);
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->mlx_img, data->player_x * 32, data->player_y * 32);

    if (key == 119 && data->map[data->player_y - 1][data->player_x] != '1') 
    {
        data->player_mov++;
        data->player_y--;
        img->mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./img/initial.xpm", &img->img_width, &img->img_height);
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->mlx_img, data->player_x * 32, data->player_y * 32);
        img->mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./img/empty.xpm", &img->img_width, &img->img_height);
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->mlx_img, data->player_x * 32, (data->player_y + 1) * 32);
    }
    if (key == 97 && data->map[data->player_y][data->player_x - 1] != '1')
    {
        data->player_mov++;
        data->player_x--;
        img->mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./img/initial.xpm", &img->img_width, &img->img_height);
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->mlx_img, data->player_x * 32, data->player_y * 32);
        img->mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./img/empty.xpm", &img->img_width, &img->img_height);
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->mlx_img, (data->player_x + 1) * 32, data->player_y * 32);
    }
    if (key == 115 && data->map[data->player_y + 1][data->player_x] != '1')
    {
        data->player_mov++;
        data->player_y++;
        img->mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./img/initial.xpm", &img->img_width, &img->img_height);
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->mlx_img, data->player_x * 32, data->player_y * 32);
        img->mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./img/empty.xpm", &img->img_width, &img->img_height);
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->mlx_img, data->player_x * 32, (data->player_y - 1) * 32);
    }
    if (key == 100 && data->map[data->player_y][data->player_x + 1] != '1')
    {
        data->player_mov++;
        data->player_x++;
        img->mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./img/initial.xpm", &img->img_width, &img->img_height);
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->mlx_img, data->player_x * 32, data->player_y * 32);
        img->mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./img/empty.xpm", &img->img_width, &img->img_height);
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->mlx_img, (data->player_x - 1) * 32, data->player_y * 32);
    }
    if (data->map[data->player_y][data->player_x] == 'C')
        data->num_collectable++;
    if(data->num_collectable >= data->num_collectable_map)
    {
        img->mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./img/exit_open.xpm", &img->img_width, &img->img_height);
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->mlx_img, data->door_x * 32, data->door_y * 32);
        if(data->map[data->player_y][data->player_x] == 'E')
        {
            printf("%s\n", "YOU ARE SAFE!");
            exit(0);
        }
    }
    ft_mov_display(data, img);
    printf("Movements: %d\n", data->player_mov);
}


void draw(int key, t_data *data, t_img *img)
{
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
                data->num_collectable_map++;
                printf("%c",'C');
                ft_collectable(data, img);
            }
            if (data->map[data->y][data->x] == 'P')
            {
                data->player_y = data->y;
                data->player_x = data->x;
                ft_initial(key, data, img);
                printf("%c",'P');
            }
            if (data->map[data->y][data->x] == 'E')
            {
                data->door_x = data->x;
                data->door_y = data->y;
                ft_exit(data, img);
                printf("%c",'E');
            }
            data->x++;
        }
        data->y++;
        printf("\n");
    }
    
}

void	move_up(t_data *data, t_img *img)
{
	
	//data->player_mov++;
 }

int	handle_keypress(int key, t_data *data, t_img *img)
{
    if (!data)
        printf("Error: data es un puntero nulo\n");
    if (!data->map)
        printf("Error: data->map es un puntero nulo\n");
    if (key == XK_Escape) //XK_Escape, 59
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		exit (1);
	}
	ft_initial(key, data, img);
    // if (key == 97 && data->map[data->player_y - 1][data->player_x] != '1' && data->map[data->player_y - 1][data->player_x] != 'E')
    //     data->player_x--;
    // if (key == 115 && data->map[data->player_y - 1][data->player_x] != '1' && data->map[data->player_y - 1][data->player_x] != 'E')
    //     data->player_y++;
    // if (key == 100 && data->map[data->player_y - 1][data->player_x] != '1' && data->map[data->player_y - 1][data->player_x] != 'E')
    //     data->player_x++;
    //draw(data, img);
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




// int render(int key, t_data *data, t_img *img)
// {
//     //render no funciona si modifico datos de las estructuras como data o img... con mlx_put_image_to_window

//     //utilizo data e img como argumentos ya que al pasarlos como variables locales de la función al acceder a ellas a través de un puntro daría seg fault.
//     //clear_background(WHITE_PIXEL, data, map);
//     //rectangle(img, 100, 100, 200, 200, data); //prueba rectangulo
// 	draw(key, data, img);
//     //mlx_clear_window(data->mlx_ptr, data->win_ptr);

// 	return(0);
// }



void    creating_window(t_data *data, t_img *img)
{
    int key;
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
    draw(key, data, img);
    //mlx_loop_hook(data->mlx_ptr, &render, data);
    


    //movements
	
    //mlx_loop_hook(data->mlx_ptr, &handle_no_event, data); //espera a recibir un evento
    mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &handle_keypress, data); //2 = KeyPress, 1<<0= KeyPressMask
	
	
	//mlx_hook(data->win_ptr, 2, 1<<0, &handle_keypress, &data);


    mlx_loop(data->mlx_ptr);
    exit(0);

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

// bugs with collectable repetition + no new image new movements