/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validating_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 21:57:32 by isromero          #+#    #+#             */
/*   Updated: 2023/04/06 20:42:20 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//tal vez deba cambiar esta función de validar ya que el return ; hace q con encontrarse uno ya no muestra si no es valido en otros
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
        if (data->map[0][x] != '1' || data->map[data->map_height - 1][x] != '1')
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
    if (found_c == true && found_e == true && found_p == true)
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

typedef struct s_point
{
    size_t  x;
    size_t  y;
}   t_point;

void flood_fill(t_data *data, size_t x, size_t y)
{
    if (x < 0 || x >= data->map_width || y < 0 || y >= data->map_height || data->map[y][x] != '0')
        return;

 	printf("Filling position (%zu, %zu)\n", x, y);
    data->map[y][x] = '2';
    printf("Map position (%zu, %zu) updated to %c\n", x, y, data->map[y][x]);

    flood_fill(data, x - 1, y);
    flood_fill(data, x + 1, y);
    flood_fill(data, x, y - 1);
    flood_fill(data, x, y + 1);
}

void find_path(t_data *data)
{
    printf("find_path called\n");

    size_t i;
    size_t j;
    t_point start;

    // Encontramos la posición inicial del jugador
    for (i = 0; i < data->map_height; i++)
    {
        for (j = 0; j < ft_strlen(data->map[i]); j++)
        {
            if (data->map[i][j] == 'P')
            {
                start.x = j;
                start.y = i;
                break;
            }
        }
    }

    flood_fill(data, start.x, start.y);

    // Verificamos si hay un camino a la salida
    for (i = 0; i < data->map_height; i++)
    {	
        for (j = 0; j < data->map_width; j++)
        {
            if (data->map[i][j] == 'E' && data->map[i][j] != '2')
            {
                ft_printf("No path to exit\n");
                exit(1);
            }
        }
    }
}


