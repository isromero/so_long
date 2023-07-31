/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 21:24:10 by isromero          #+#    #+#             */
/*   Updated: 2023/07/31 21:37:30 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	check_chars(t_data *data, bool *found_c, bool *found_e, bool *found_p)
{
	size_t	x; 
	size_t	y;

	y = 0;
	while (y < data->map_height) 
	{
		x = 0;
		while (x < data->map_width) 
		{
			if (data->map[y][x] == 'C') 
				*found_c = true;
			else if (data->map[y][x] == 'E')
				*found_e = true;
			else if (data->map[y][x] == 'P')
				*found_p = true;
			else if (!(data->map[y][x] == '1' || data->map[y][x] == '0'
				|| data->map[y][x] == 'C' || data->map[y][x] == 'E'
				|| data->map[y][x] == 'P'))
			{
				ft_printf(RED "Wrong chars\n" RESET);
				exit(1);
			}
			x++;
		}
		y++;
	}
}
