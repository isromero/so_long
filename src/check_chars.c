/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 21:24:10 by isromero          #+#    #+#             */
/*   Updated: 2023/08/06 13:59:51 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

bool	all_chars(char character)
{
	return (character == '1' || character == '0'
		|| character == 'C' || character == 'E' || character == 'P');
}

void	check_chars(t_data *data, bool *found_c, int *found_e, int *found_p)
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
				*found_e += 1;
			else if (data->map[y][x] == 'P')
				*found_p += 1;
			else if (!all_chars(data->map[y][x]))
			{
				ft_printf(RED "Wrong chars\n" RESET);
				exit(1);
			}
			x++;
		}
		y++;
	}
}
