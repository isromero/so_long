/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 21:03:07 by isromero          #+#    #+#             */
/*   Updated: 2023/07/31 21:33:11 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	flood_fill(t_data *data, size_t x, size_t y)
{
	if ((int)x < 0 || (int)y < 0
		|| x >= data->map_width || y >= data->map_height)
		return ;
	if (data->map[y][x] == '2')
		return ;
	if (data->map[y][x] == '1')
		return ;
	if (data->map[y][x] == 'E') 
	{
		data->map[y][x] = '2';
		return ;
	}
	data->map[y][x] = '2';
	flood_fill(data, x + 1, y);
	flood_fill(data, x - 1, y);
	flood_fill(data, x, y + 1);
	flood_fill(data, x, y - 1);
}

void	check_path_not_found(t_data *data)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (x < data->map_width)
		{
			if (data->map[y][x] == 'E' && data->map[y][x] != '2')
			{
				ft_printf(RED "Path not found\n" RESET);
				exit(1);
			}
			x++;
		}
		y++;
	}
}
