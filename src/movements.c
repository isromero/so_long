/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 22:29:58 by isromero          #+#    #+#             */
/*   Updated: 2023/08/06 13:58:45 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	player_above_door(t_data *data, t_img *img, int player_x, int player_y)
{
	img->mlx_img = mlx_xpm_file_to_image(data->mlx_ptr,
			"./img/exit_closed.xpm", &img->img_width, &img->img_height);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		img->mlx_img, player_x * 32, player_y * 32);
	mlx_destroy_image(data->mlx_ptr, img->mlx_img);
}

void	move_up(int key, t_data *data)
{
	t_img	img;

	if ((key == 119 || key == 13)
		&& data->map[data->player_y - 1][data->player_x] != '1')
	{
		data->player_mov++;
		data->player_y--;
		img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./img/initial.xpm",
				&img.img_width, &img.img_height);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			img.mlx_img, data->player_x * 32, data->player_y * 32);
		mlx_destroy_image(data->mlx_ptr, img.mlx_img);
		img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./img/empty.xpm",
				&img.img_width, &img.img_height);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			img.mlx_img, data->player_x * 32, (data->player_y + 1) * 32);
		mlx_destroy_image(data->mlx_ptr, img.mlx_img);
		if (data->map[data->player_y + 1][data->player_x] == 'E')
			player_above_door(data, &img, data->player_x, data->player_y + 1);
	}
}

void	move_left(int key, t_data *data)
{
	t_img	img;

	if ((key == 97 || key == 0)
		&& data->map[data->player_y][data->player_x - 1] != '1')
	{
		data->player_mov++;
		data->player_x--;
		img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./img/initial.xpm",
				&img.img_width, &img.img_height);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img.mlx_img,
			data->player_x * 32, data->player_y * 32);
		mlx_destroy_image(data->mlx_ptr, img.mlx_img);
		img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./img/empty.xpm",
				&img.img_width, &img.img_height);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img.mlx_img,
			(data->player_x + 1) * 32, data->player_y * 32);
		mlx_destroy_image(data->mlx_ptr, img.mlx_img);
		if (data->map[data->player_y][data->player_x + 1] == 'E')
			player_above_door(data, &img, data->player_x + 1, data->player_y);
	}
}

void	move_down(int key, t_data *data)
{
	t_img	img;

	if ((key == 115 || key == 1)
		&& data->map[data->player_y + 1][data->player_x] != '1')
	{
		data->player_mov++;
		data->player_y++;
		img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./img/initial.xpm",
				&img.img_width, &img.img_height);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img.mlx_img,
			data->player_x * 32, data->player_y * 32);
		mlx_destroy_image(data->mlx_ptr, img.mlx_img);
		img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./img/empty.xpm",
				&img.img_width, &img.img_height);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img.mlx_img,
			data->player_x * 32, (data->player_y - 1) * 32);
		mlx_destroy_image(data->mlx_ptr, img.mlx_img);
		if (data->map[data->player_y - 1][data->player_x] == 'E')
			player_above_door(data, &img, data->player_x, data->player_y - 1);
	}
}

void	move_right(int key, t_data *data)
{
	t_img	img;

	if ((key == 100 || key == 2)
		&& data->map[data->player_y][data->player_x + 1] != '1')
	{
		data->player_mov++;
		data->player_x++;
		img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./img/initial.xpm",
				&img.img_width, &img.img_height);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img.mlx_img,
			data->player_x * 32, data->player_y * 32);
		mlx_destroy_image(data->mlx_ptr, img.mlx_img);
		img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./img/empty.xpm",
				&img.img_width, &img.img_height);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img.mlx_img,
			(data->player_x - 1) * 32, data->player_y * 32);
		mlx_destroy_image(data->mlx_ptr, img.mlx_img);
		if (data->map[data->player_y][data->player_x - 1] == 'E')
			player_above_door(data, &img, data->player_x - 1, data->player_y);
	}
}
