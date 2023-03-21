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

//tal vez deba cambiar esta función de validar ya que el return ; hace q con encontrarse uno ya no muestra si no es valido en otros
void    validating_walls(t_data *data)
{
    int     x;
    int     y;

    x = 0;
    y = 0;
    while(y < data->map_height) 
    {
        if (data->map[y][0] != '1')
        {
            printf("Not valid walls on the left\n");
            return ;
        }
        if (data->map[y][data->map_width - 1] != '1')
        {
            printf("Not valid walls on the right\n");
            return ;
        }
        y++;
    }
    while(x < data->map_width)
    {
        if (data->map[0][x] != '1' || data->map[data->map_height - 1][x] != '1')
        {
            printf("Not valid walls on the top or/and bottom\n");
            return ;
        }
        x++;
    }
    printf("Valid walls...\n");
}

void validating_chars(t_data *data)
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
            if (data->map[y][x] == 'C') 
                found_c = true;
            else if (data->map[y][x] == 'E')
                found_e = true;
            else if (data->map[y][x] == 'P')
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

void validating_rect(t_data *data)
{
    int y;
    y = 0;
    //reservar memoria?
    //printf("expectated width: %d\n", data->map_width);
    //EL VALOR DA SEG FAULT PORQUE PREDETERMINADAMENTE MAP[Y] TIENE UN VALOR NO CAMBIABLE?
    while(y < data->map_height)
    {
        if(strlen(data->map[y]) != data->map_width)
        {
            printf("%d\n", data->map_width);
            printf("%ld\n", strlen(data->map[y]));
            printf("Map is not a rectangle\n");
            exit(1);
        }
        
        y++;
    }
    printf("Valid rectangle\n");
}

void    ft_empty(t_data *data, t_img *img)
{
    img->mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "img/empty.xpm", &img->img_width, &img->img_height);
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->mlx_img, data->x * 32, data->y * 32);
}

void    ft_wall(t_data *data, t_img *img)
{
    img->mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "img/walls.xpm", &img->img_width, &img->img_height);
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->mlx_img, data->x * 32, data->y * 32);
}

void    ft_collectable(t_data *data, t_img *img)
{
    img->mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "img/collectable.xpm", &img->img_width, &img->img_height);
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->mlx_img, data->x * 32, data->y * 32);
}

void    ft_exit(t_data *data, t_img *img)
{
    img->mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "img/exit_closed.xpm", &img->img_width, &img->img_height);
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
    int i = 0;

    img->mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./img/empty.xpm", &img->img_width, &img->img_height);
    while (i < (32 * data->map_width))
    {
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->mlx_img, i, data->map_height * 32);
        i += 32;
    }
   	mlx_string_put(data->mlx_ptr, data->win_ptr,
		data->map_width / 2, data->map_height * 34, 0xff0000,
		"MOVEMENTS ");
    mlx_string_put(data->mlx_ptr, data->win_ptr,
		data->map_width * 31, data->map_height * 34, 0xff0000,
		ft_itoa(data->player_mov));
}



void    ft_initial(int key, t_data *data)
{
	t_img img;
    img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "img/initial.xpm", &img.img_width, &img.img_height);
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img.mlx_img, data->player_x * 32, data->player_y * 32);

    if ((key == 119 || key == 13) && data->map[data->player_y - 1][data->player_x] != '1' && data->map[data->player_y - 1][data->player_x] != 'E') //13
    {
        data->player_mov++;
        data->player_y--;
        img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "img/initial.xpm", &img.img_width, &img.img_height);
       	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img.mlx_img, data->player_x * 32, data->player_y * 32);
        img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "img/empty.xpm", &img.img_width, &img.img_height);
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img.mlx_img, data->player_x * 32, (data->player_y + 1) * 32);
		// if (data->map[data->player_y][data->player_x] == 'E' && key == 13)
		// {
		// 	img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "img/exit_closed.xpm", &img.img_width, &img.img_height);
        // 	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img.mlx_img, data->player_x * 32, (data->player_y) * 32);
		// }
     }
    if ((key == 97 || key == 0) && data->map[data->player_y][data->player_x - 1] != '1' && data->map[data->player_y][data->player_x - 1] != 'E') //0
    {
		
        data->player_mov++;
        data->player_x--;
        img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./img/initial.xpm", &img.img_width, &img.img_height);
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img.mlx_img, data->player_x * 32, data->player_y * 32);
        img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./img/empty.xpm", &img.img_width, &img.img_height);
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img.mlx_img, (data->player_x + 1) * 32, data->player_y * 32);
		// if (data->map[data->player_y][data->player_x] == 'E' && key == 0)
		// {
		// 	img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./img/exit_closed.xpm", &img.img_width, &img.img_height);
       	// 	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img.mlx_img, (data->player_x) * 32, data->player_y * 32);
		// }
    }
    if ((key == 115 || key == 1) && data->map[data->player_y + 1][data->player_x] != '1' && data->map[data->player_y + 1][data->player_x] != 'E') //1
    {
        data->player_mov++;
        data->player_y++;
        img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./img/initial.xpm", &img.img_width, &img.img_height);
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img.mlx_img, data->player_x * 32, data->player_y * 32);
        img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./img/empty.xpm", &img.img_width, &img.img_height);
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img.mlx_img, data->player_x * 32, (data->player_y - 1) * 32);
		// if (data->map[data->player_y][data->player_x] == 'E' && key == 1) // DUPLICATED DOORS
		// {
		// 	img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./img/exit_closed.xpm", &img.img_width, &img.img_height);
        // 	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img.mlx_img, data->player_x * 32, (data->player_y) * 32); // change this
		// }
    }
    if ((key == 100 || key == 2)&& data->map[data->player_y][data->player_x + 1] != '1' && data->map[data->player_y][data->player_x + 1] != 'E') //2
    {
        data->player_mov++;
        data->player_x++;
        img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./img/initial.xpm", &img.img_width, &img.img_height);
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img.mlx_img, data->player_x * 32, data->player_y * 32);
        img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./img/empty.xpm", &img.img_width, &img.img_height);
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img.mlx_img, (data->player_x - 1) * 32, data->player_y * 32);
		// if (data->map[data->player_y][data->player_x] == 'E' && key == 2)
		// {
		// 	img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./img/exit_closed.xpm", &img.img_width, &img.img_height);
       	// 	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img.mlx_img, (data->player_x) * 32, data->player_y * 32);
		// }
    }
	if (data->map[data->player_y][data->player_x] == 'C')
	{
		data->map[data->player_y][data->player_x] = '0';
       	data->num_collectable++;
	}
	if(data->num_collectable_map == data->num_collectable)
    {
        img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./img/exit_open.xpm", &img.img_width, &img.img_height);
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img.mlx_img, data->door_x * 32, data->door_y * 32);
		if(((key == 119 || key == 13) && data->map[data->player_y - 1][data->player_x] == 'E') || ((key == 97 || key == 0) && data->map[data->player_y][data->player_x - 1] == 'E') || 
        ((key == 115 || key == 1) && data->map[data->player_y + 1][data->player_x] == 'E') || ((key == 100 || key == 2) && data->map[data->player_y][data->player_x + 1] == 'E')) //Con esto solucionas el no pasar por arriba de la puerta hasta q no se colecione todo
        {
            printf("%s\n", "YOU ARE SAFE!");
            exit(0);
       	}
    }
    // ft_empty(data, &img);
    // ft_exit(data, &img);
    // ft_wall(data, &img);
    // ft_collectable(data, &img);
    // render all in MACOS? No necesito estas funciones pero tal vez en mac hagan q no se duplique la puerta PROBAR-----------------------------------------------------------------------------------------------------
    ft_mov_display(data, &img);
    printf("Movements: %d\n", data->player_mov);
}

void draw(int key, t_data *data, t_img *img)
{
	data->y = 0;
	data->x = 0;
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
            else if (data->map[data->y][data->x] == '1')
            {
                ft_wall(data, img);
                printf("%c",'1');
            }
            else if (data->map[data->y][data->x] == 'C')
            {
                printf("%c",'C');
                ft_collectable(data, img);
            }
            else if (data->map[data->y][data->x] == 'P')
            {
                data->player_y = data->y;
                data->player_x = data->x;
                ft_initial(key, data);
                printf("%c",'P');
            }
            else if (data->map[data->y][data->x] == 'E')
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
int	handle_keypress(int key, t_data *data)
{
    if (!data) //meter exit
        printf("Error: data es un puntero nulo\n");
    if (!data->map)
        printf("Error: data->map es un puntero nulo\n");
    if (key == 59 || key == 9) //XK_Escape, 59
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		exit (1);
	}
	ft_initial(key, data);
    return (0);
}
int handle_esc_screen(t_data *data)
{
    mlx_destroy_window(data->mlx_ptr, data->win_ptr);
    exit(0);
    return(0);
}

void    creating_window(int key, t_data *data, t_img *img)
{
    int width = 0;
    width = data->map_width * 32;
    int height = 0;
    height = data->map_height * 32;
    data->mlx_ptr = mlx_init();
    data->win_ptr = mlx_new_window(data->mlx_ptr, width, height + 32, "so_long");
    img->mlx_img = mlx_new_image(data->mlx_ptr, width, height); //crea una imagen en la memoria de video de la pantalla
    img->addr = mlx_get_data_addr(img->mlx_img, &img->bpp, &img->line_len, &img->endian); //se devuelve un puntero al primer byte de la imagen donde se usa para escribir en ella pixel por pixel
	init_points(data);
    draw(key, data, img);
    mlx_key_hook(data->win_ptr, handle_keypress, data);
    mlx_hook(data->win_ptr, 17, 1L<<0, handle_esc_screen, data);
    mlx_loop(data->mlx_ptr);

    //exit(0);

    mlx_destroy_image(data->mlx_ptr, img->mlx_img);
    mlx_destroy_display(data->mlx_ptr);
    free(data->mlx_ptr);
}

void    so_long(int key, t_data *data, t_img *img)
{
    validating_rect(data);
    validating_walls(data);
    validating_chars(data);
    creating_window(key, data, img);
}

static int	countwords(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s != '\0')
			count++;
		while (*s != '\0' && *s != c)
			s++;
	}
	return (count);
}

static char	*getword(const char *s, char c)
{
	int		n;
	int		i;
	char	*word;

	i = 0;
	n = 0;
	while (s[n] && s[n] != c)
		n++;
	word = (char *)malloc(sizeof(char) * (n + 1));
	if (!word)
		return (0);
	while (i < n)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	int		i;

	i = 0;
	if (!s)
		return (0);
	p = (char **)malloc(sizeof(char *) * (countwords(s, c) + 1));
	if (!p)
		return (0);
	while (*s != '\0')
	{
		while (*s != '\0' && *s == c)
			s++;
		if (*s != '\0')
		{
			p[i++] = getword(s, c);
			if (p[i - 1] == NULL)
				free (p);
		}
		while (*s != '\0' && *s != c)
			s++;
	}
	p[i] = NULL;
	return (p);
}

char	*ft_strchr2(const char *s, int c)
{
	char	*p;

	p = (char *)s;
	while (*p && *p != (char) c)
		p++;
	if (*p == (char) c)
		return (p);
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*sub;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (0);
	while (s[i] != '\0')
	{	
		if (i >= start && j < len)
		{
			sub[j] = s[i];
			j++;
		}
		i++;
	}
	sub[j] = '\0';
	return (sub);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;

	if (!s1 || !set)
		return (0);
	while (*s1 && ft_strchr2(set, *s1))
		s1++;
	len = ft_strlen(s1) + 1;
	while (len && ft_strchr2(set, s1[len - 1]))
		len--;
	return (ft_substr(s1, 0, len));
}


char **just_read_and_info(char *filename)
{
    int		fd;
    char	*line;
    char	*joined_lines;

    line = NULL;
    joined_lines = NULL;
    fd = open(filename, O_RDONLY);
    if (fd < 0)
        exit(1);
   while ((line = get_next_line(fd)))
    {
        if (line[0] == '\n')
            break ;
        char *trimmed_line= ft_strtrim(line, "\n\t\r\f\v");
        joined_lines = ft_strjoin(joined_lines, trimmed_line);
        joined_lines = ft_strjoin(joined_lines, "\n");
        free(line);
        free(trimmed_line);
    }
    free(line);
    close(fd);
    if (!joined_lines || joined_lines[0] == '\0')
        exit(1);
    return (ft_split(joined_lines, '\n'));
}

int main(int argc, char **argv)
{
	int key;
	
    t_data  data;
    t_img   img;

    key = 0;
    if(argc == 1)
    {
        printf("no arguments\n");
        exit(1);
    }
    if(argc > 2)
    {
        printf("the first file is the valid one\n");
        exit(1);
    }

    //tal vez hay que revisar si es archivo .ber
    data.map = just_read_and_info(argv[1]);
	init_data(&data);
    so_long(key, &data, &img);
    return (0);
}