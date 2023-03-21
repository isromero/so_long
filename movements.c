/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 22:29:58 by isromero          #+#    #+#             */
/*   Updated: 2023/03/21 22:30:39 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    move_up(int key, t_data *data)
{
    t_img img;
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
}

void    move_left(int key, t_data *data)
{
    t_img img;
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
}
void    move_down(int key, t_data *data)
{
    t_img img;
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
}

void    move_right(int key, t_data *data)
{
    t_img img;
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
}


void    ft_move_initial(int key, t_data *data)
{
	t_img img;
    img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "img/initial.xpm", &img.img_width, &img.img_height);
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img.mlx_img, data->player_x * 32, data->player_y * 32);

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
        img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./img/exit_open.xpm", &img.img_width, &img.img_height);
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img.mlx_img, data->door_x * 32, data->door_y * 32);
		if(((key == 119 || key == 13) && data->map[data->player_y - 1][data->player_x] == 'E') || ((key == 97 || key == 0) && data->map[data->player_y][data->player_x - 1] == 'E') || 
        ((key == 115 || key == 1) && data->map[data->player_y + 1][data->player_x] == 'E') || ((key == 100 || key == 2) && data->map[data->player_y][data->player_x + 1] == 'E')) //Con esto solucionas el no pasar por arriba de la puerta hasta q no se colecione todo
        {
            ft_printf("%s\n", "YOU ARE SAFE!");
            exit(0);
       	}
    }
    // ft_empty(data, &img);
    // ft_exit(data, &img);
    // ft_wall(data, &img);
    // ft_collectable(data, &img);
    // render all in MACOS? No necesito estas funciones pero tal vez en mac hagan q no se duplique la puerta PROBAR-----------------------------------------------------------------------------------------------------
    ft_mov_display(data, &img);
    ft_printf("Movements: %d\n", data->player_mov);
}