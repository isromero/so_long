/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validating_walls.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 21:17:23 by isromero          #+#    #+#             */
/*   Updated: 2023/07/31 21:25:42 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

bool	check_walls_left_right(t_data *data, bool invalid_walls)
{
	size_t	y;

	y = 0;
	while (y < data->map_height) 
	{
		if (data->map[y][0] != '1')
		{
			ft_printf(RED "Not valid walls on the left\n" RESET);
			invalid_walls = true;
		}
		if (data->map[y][data->map_width - 1] != '1')
		{
			ft_printf(RED "Not valid walls on the right\n" RESET);
			invalid_walls = true;
		}
		y++;
	}
	return (invalid_walls);
}

bool	check_walls_top_bottom(t_data *data, bool invalid_walls)
{
	size_t	x;

	x = 0;
	while (x < data->map_width) 
	{
		if (data->map[0][x] != '1')
		{
			ft_printf(RED "Not valid walls on the top\n" RESET);
			invalid_walls = true;
		}
		if (data->map[data->map_height - 1][x] != '1')
		{
			ft_printf(RED "Not valid walls on the bottom\n" RESET);
			invalid_walls = true;
		}
		x++;
	}
	return (invalid_walls);
}
