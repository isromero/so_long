/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 22:29:58 by isromero          #+#    #+#             */
/*   Updated: 2023/04/06 17:28:04 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    move_up(int key, t_data *data)
{
    t_img img;
    if ((key == 119 || key == 13) && data->map[data->player_y - 1][data->player_x] != '1')
    {
        data->player_mov++;
        data->player_y--;
        img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "img/initial.xpm", &img.img_width, &img.img_height);
       	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img.mlx_img, data->player_x * 32, data->player_y * 32);
		mlx_destroy_image(data->mlx_ptr, img.mlx_img);
        img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "img/empty.xpm", &img.img_width, &img.img_height);
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img.mlx_img, data->player_x * 32, (data->player_y + 1) * 32);
		mlx_destroy_image(data->mlx_ptr, img.mlx_img);
        if (data->map[data->player_y + 1][data->player_x] == 'E')
        {
            img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "img/exit_closed.xpm", &img.img_width, &img.img_height);
            mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img.mlx_img, data->player_x * 32, (data->player_y + 1) * 32);
			mlx_destroy_image(data->mlx_ptr, img.mlx_img);
        }
     }
}

void    move_left(int key, t_data *data)
{
    t_img img;
    if ((key == 97 || key == 0) && data->map[data->player_y][data->player_x - 1] != '1') //0
    {
		
        data->player_mov++;
        data->player_x--;
        img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./img/initial.xpm", &img.img_width, &img.img_height);
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img.mlx_img, data->player_x * 32, data->player_y * 32);
		mlx_destroy_image(data->mlx_ptr, img.mlx_img);
        img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./img/empty.xpm", &img.img_width, &img.img_height);
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img.mlx_img, (data->player_x + 1) * 32, data->player_y * 32);
		mlx_destroy_image(data->mlx_ptr, img.mlx_img);
        if(data->map[data->player_y][data->player_x + 1] == 'E')
        {
            img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./img/exit_closed.xpm", &img.img_width, &img.img_height);
            mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img.mlx_img, (data->player_x + 1) * 32, data->player_y * 32);
			mlx_destroy_image(data->mlx_ptr, img.mlx_img);
        }
    }
}
void    move_down(int key, t_data *data)
{
    t_img img;
    if ((key == 115 || key == 1) && data->map[data->player_y + 1][data->player_x] != '1') //1
    {
        data->player_mov++;
        data->player_y++;
        img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./img/initial.xpm", &img.img_width, &img.img_height);
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img.mlx_img, data->player_x * 32, data->player_y * 32);
		mlx_destroy_image(data->mlx_ptr, img.mlx_img);
        img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./img/empty.xpm", &img.img_width, &img.img_height);
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img.mlx_img, data->player_x * 32, (data->player_y - 1) * 32);
		mlx_destroy_image(data->mlx_ptr, img.mlx_img);
        if(data->map[data->player_y - 1][data->player_x] == 'E')
        {
            img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./img/exit_closed.xpm", &img.img_width, &img.img_height);
            mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img.mlx_img, data->player_x * 32, (data->player_y - 1) * 32);
			mlx_destroy_image(data->mlx_ptr, img.mlx_img);
        }
    }
}

void    move_right(int key, t_data *data)
{
    t_img img;
    if ((key == 100 || key == 2)&& data->map[data->player_y][data->player_x + 1] != '1') //2
    {
        data->player_mov++;
        data->player_x++;
        img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./img/initial.xpm", &img.img_width, &img.img_height);
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img.mlx_img, data->player_x * 32, data->player_y * 32);
		mlx_destroy_image(data->mlx_ptr, img.mlx_img);
        img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./img/empty.xpm", &img.img_width, &img.img_height);
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img.mlx_img, (data->player_x - 1) * 32, data->player_y * 32);
		mlx_destroy_image(data->mlx_ptr, img.mlx_img);
        if(data->map[data->player_y][data->player_x - 1] == 'E')
        {
            img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./img/exit_closed.xpm", &img.img_width, &img.img_height);
            mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img.mlx_img, (data->player_x - 1) * 32, data->player_y * 32);
			mlx_destroy_image(data->mlx_ptr, img.mlx_img);
        }
    }
}

void    ft_move_initial(int key, t_data *data)
{
	t_img img;
    img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "img/initial.xpm", &img.img_width, &img.img_height);
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img.mlx_img, data->player_x * 32, data->player_y * 32);
	mlx_destroy_image(data->mlx_ptr, img.mlx_img);

    move_up(key, data);
    move_left(key, data);
    move_down(key, data);
    move_right(key, data);
	if (data->map[data->player_y][data->player_x] == 'C')
	{
		data->map[data->player_y][data->player_x] = '0';
       	data->num_collectable++;
	}
	if(data->num_collectable_map == data->num_collectable)
    {
		img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./img/empty.xpm", &img.img_width, &img.img_height);
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img.mlx_img, data->door_x * 32, data->door_y * 32);
		mlx_destroy_image(data->mlx_ptr, img.mlx_img);
        img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./img/exit_open.xpm", &img.img_width, &img.img_height);
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img.mlx_img, data->door_x * 32, data->door_y * 32);
		mlx_destroy_image(data->mlx_ptr, img.mlx_img);
		if(data->map[data->player_y][data->player_x] == 'E') //Con esto solucionas el no pasar por arriba de la puerta hasta q no se colecione todo
        {
            ft_printf("%s\n", "YOU ARE SAFE!");
            exit(0);
       	}
    }
    ft_printf("Movements: %d\n", data->player_mov);
}