/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validating_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 21:57:32 by isromero          #+#    #+#             */
/*   Updated: 2023/05/22 18:03:44 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    validating_walls(t_data *data)
{
    size_t     x;
    size_t     y;
	bool       invalid_walls;
	 
	invalid_walls = false;
    x = 0;
    y = 0;
    while(y < data->map_height) 
    {
        if (data->map[y][0] != '1')
        {
            ft_printf("Not valid walls on the left\n");
            invalid_walls = true;
        }
        if (data->map[y][data->map_width - 1] != '1')
        {
            ft_printf("Not valid walls on the right\n");
            invalid_walls = true;
        }
        y++;
    }
    while(x < data->map_width)
    {
        if (data->map_height > 1 && (data->map[0][x] != '1' || data->map[data->map_height - 1][x] != '1'))
        {
            ft_printf("Not valid walls on the top or/and bottom\n");
            invalid_walls = true;
        }
        x++;
    }
	if (!invalid_walls)
    	ft_printf("Valid walls\n");
	else
		exit(1);
}

void validating_chars(t_data *data)
{
    size_t x; 
    size_t y;
    bool found_c = false, found_e = false, found_p = false;

    x = 0;
    y = 0;
    while (y < data->map_height) 
    {
        x = 0;
        while (x < data->map_width) 
        {
            if (data->map[y][x] == 'C') 
                found_c = true;
            else if (data->map[y][x] == 'E')
                found_e = true;
            else if (data->map[y][x] == 'P')
                found_p = true;
             else if (data->map[y][x] != '1' && data->map[y][x] != '0' && data->map[y][x] != 'P' && data->map[y][x] != 'C' && data->map[y][x] != 'E')
            {
                ft_printf("Wrong chars\n");
                exit(1);
            }
            x++;
			
        }
        y++;
    }
	if (found_c != true || found_e != true || found_p != true)
	{
        ft_printf("Doesn't have 'C', 'E', 'P'\n");
		exit(1);
	}
   
   else if (found_c == true && found_e == true && found_p == true)
        ft_printf("Valid chars\n");
}

void validating_rect(t_data *data)
{
    size_t y;
    y = 0;
   
    while(y < data->map_height)
    {
        if(ft_strlen(data->map[y]) != data->map_width)
        {
            ft_printf("Map is not a rectangle\n");
            exit(1);
        }
        y++;
    }
    printf("Valid rectangle\n");
}

void	check_dotber(char *argv)
{
	int len;

	len = ft_strlen(argv);
	
	if(ft_strncmp(argv + len - 4, ".ber", len) == 0)
		ft_printf("Valid .ber\n");
	if(ft_strncmp(argv + len - 4, ".ber", len) != 0)
	{
		ft_printf("Map is not .ber\n");
		exit(1);
	}
}

void flood_fill(t_data *data, size_t x, size_t y)
{
    // Verificar si las coordenadas están dentro de la matriz
    if ((int)x < 0 || (int)y < 0 || x >= data->map_width || y >= data->map_height)
        return;

    // Verificar si la celda actual ya fue visitada
    if (data->map[y][x] == '2')
        return ;

    // Verificar si la celda actual es un obstáculo
    if (data->map[y][x] == '1')
        return ;

    // Verificar si la celda actual es la puerta
    if (data->map[y][x] == 'E') 
	{
        data->map[y][x] = '2';
        return;
    }

    // Marcar la celda actual como visitada
    data->map[y][x] = '2';

    // Continuar la recursión desde las celdas adyacentes
    flood_fill(data, x + 1, y);
    flood_fill(data, x - 1, y);
    flood_fill(data, x, y + 1);
    flood_fill(data, x, y - 1);
}

void find_path(t_data *data)
{

    size_t x;
    size_t y;
    size_t initial_x;
    size_t initial_y;

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
    y = 0;
    while (y < data->map_height)
    {
        x = 0;
        while (x < data->map_width)
        {
            if (data->map[y][x] == 'E' && data->map[y][x] != '2')
            {
                printf("error\n");
                exit(1);
            }
            x++;
        }
        y++;
    }
    data->map[initial_y][initial_x] = 'P';
}


