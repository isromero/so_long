/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validating_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 21:57:32 by isromero          #+#    #+#             */
/*   Updated: 2023/08/02 20:23:15 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	validating_walls(t_data *data)
{
	bool	invalid_walls;

	invalid_walls = false;
	invalid_walls = check_walls_left_right(data, invalid_walls);
	invalid_walls = check_walls_top_bottom(data, invalid_walls);
	if (!invalid_walls)
		ft_printf(GREEN "Valid walls\n" RESET);
	else
		exit(1);
}

void	validating_chars(t_data *data)
{
	bool	found_c;
	int		found_e;
	int		found_p;

	found_c = false;
	found_e = 0;
	found_p = 0;
	check_chars(data, &found_c, &found_e, &found_p);
	if (found_c != true || found_e != 1 || found_p != 1)
	{
		ft_printf(RED "Wrong chars\n" RESET);
		exit(1);
	}
	else if (found_c == true && found_e >= 1 && found_p >= 1)
		ft_printf(GREEN "Valid chars\n" RESET);
}

void	validating_rect(t_data *data)
{
	size_t	y;

	y = 0;
	while (y < data->map_height)
	{
		if (ft_strlen(data->map[y]) != data->map_width)
		{
			ft_printf(RED "Map is not a rectangle\n" RESET);
			exit(1);
		}
		y++;
	}
	ft_printf(GREEN "Valid rectangle\n" RESET);
}

void	validating_path(t_data *data)
{
	size_t	x;
	size_t	y;
	size_t	initial_x;
	size_t	initial_y;

	x = 0;
	y = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (x < data->map_width)
		{
			if (data->map[y][x] == 'P')
			{
				initial_x = x;
				initial_y = y;
			}
			x++;
		}
		y++;
	}
	flood_fill(data, initial_x, initial_y);
	check_path_not_found(data);
	data->map[initial_y][initial_x] = 'P';
	ft_printf(GREEN "Valid path\n" RESET);
}

void	check_dotber(char *argv)
{
	int	len;

	len = ft_strlen(argv);
	if (ft_strncmp(argv + len - 4, ".ber", len) == 0)
		ft_printf(GREEN "Valid .ber\n" RESET);
	if (ft_strncmp(argv + len - 4, ".ber", len) != 0)
	{
		ft_printf(RED "Map is not .ber\n" RESET);
		exit(1);
	}
}
