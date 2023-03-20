/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:15:18 by isromero          #+#    #+#             */
/*   Updated: 2023/03/20 22:16:45 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void init_data(t_data *data)
{
    data->mlx_ptr = NULL;
    data->win_ptr = NULL;
    data->current_img = 0;
   	data->map = NULL;
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
	data->map_width = 0;
	data->map_height = 0;
}

void init_points(t_data *data)
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