/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 20:38:49 by isromero          #+#    #+#             */
/*   Updated: 2023/07/31 21:01:00 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_move_initial(int key, t_data *data)
{
	t_img	img;

	img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./img/initial.xpm",
			&img.img_width, &img.img_height);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		img.mlx_img, data->player_x * 32, data->player_y * 32);
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
	if (data->num_collectable_map == data->num_collectable)
		finish_game(data, &img);
	ft_mov_display(data, &img);
	ft_printf("Movements: %d\n", data->player_mov);
}

void	finish_game(t_data *data, t_img *img)
{
	img->mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./img/empty.xpm",
			&img->img_width, &img->img_height);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		img->mlx_img, data->door_x * 32, data->door_y * 32);
	mlx_destroy_image(data->mlx_ptr, img->mlx_img);
	img->mlx_img = mlx_xpm_file_to_image(data->mlx_ptr,
			"./img/exit_open.xpm", &img->img_width, &img->img_height);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		img->mlx_img, data->door_x * 32, data->door_y * 32);
	mlx_destroy_image(data->mlx_ptr, img->mlx_img);
	if (data->map[data->player_y][data->player_x] == 'E')
	{
		ft_printf("%s\n", "YOU ARE SAFE!");
		exit(0);
	}
}
