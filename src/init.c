/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:15:18 by isromero          #+#    #+#             */
/*   Updated: 2023/07/31 20:21:30 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

size_t	map_height(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
		i++;
	return (i);
}

void	init_data(t_data *data)
{
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->door_x = 0;
	data->door_y = 0;
	data->num_collectable_map = 0;
	data->num_collectable = 0;
	data->key = 0;
	data->x = 0;
	data->y = 0;
	data->player_x = 0;
	data->player_y = 0;
	data->player_mov = 0;
	data->map_width = ft_strlen(data->map[0]);
	data->map_height = map_height(data->map);
}

void	init_points(t_data *data)
{
	data->x = 0;
	data->y = 0;
	while (data->y < data->map_height) 
	{
		data->x = 0;
		while (data->x < data->map_width) 
		{
			if (data->map[data->y][data->x] == 'C') 
			{
				data->num_collectable_map++;
			}
			data->x++;
		}
		data->y++;
	}
}
