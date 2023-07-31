/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_and_windows.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 22:32:46 by isromero          #+#    #+#             */
/*   Updated: 2023/07/31 20:37:53 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	handle_keypress(int key, t_data *data)
{
	if (key == 53 || key == 9) //XK_Escape, 59
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		exit (1);
	}
	ft_move_initial(key, data);
	return (0);
}

int	handle_esc_screen(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit(0);
	return (0);
}

void	ft_mov_display(t_data *data, t_img *img)
{
	size_t	i;
	char	*movements_str;

	i = 0;
	img->mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./img/empty.xpm",
			&img->img_width, &img->img_height);
	while (i < (32 * data->map_width))
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			img->mlx_img, i, data->map_height * 32);
		i += 32;
	}
	mlx_string_put(data->mlx_ptr, data->win_ptr,
		data->map_width / 2, data->map_height * 34, 0xff0000,
		"MOVEMENTS ");
	movements_str = ft_itoa(data->player_mov);
	mlx_string_put(data->mlx_ptr, data->win_ptr,
		data->map_width * 30, data->map_height * 34, 0xff0000,
		movements_str);
	free(movements_str);
}

void	creating_window(t_data *data, t_img *img)
{
	int	width;
	int	height;

	width = data->map_width * 32;
	height = data->map_height * 32;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(
			data->mlx_ptr, width, height + 32, "so_long");
	img->mlx_img = mlx_new_image(data->mlx_ptr, width, height);
	img->addr = mlx_get_data_addr(
			img->mlx_img, &img->bpp, &img->line_len, &img->endian);
	init_points(data);
	draw(data, img);
	mlx_key_hook(data->win_ptr, handle_keypress, data);
	mlx_hook(data->win_ptr, 17, 1L << 0, handle_esc_screen, data);
	mlx_loop(data->mlx_ptr);
}
