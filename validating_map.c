/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validating_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 21:57:32 by isromero          #+#    #+#             */
/*   Updated: 2023/03/22 19:01:32 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//tal vez deba cambiar esta función de validar ya que el return ; hace q con encontrarse uno ya no muestra si no es valido en otros
void    validating_walls(t_data *data)
{
    size_t     x;
    size_t     y;

    x = 0;
    y = 0;
    while(y < data->map_height) 
    {
        if (data->map[y][0] != '1')
        {
            printf("Not valid walls on the left\n");
            return ;
        }
        if (data->map[y][data->map_width - 1] != '1')
        {
            printf("Not valid walls on the right\n");
            return ;
        }
        y++;
    }
    while(x < data->map_width)
    {
        if (data->map[0][x] != '1' || data->map[data->map_height - 1][x] != '1')
        {
            printf("Not valid walls on the top or/and bottom\n");
            return ;
        }
        x++;
    }
    printf("Valid walls...\n");
}

void validating_chars(t_data *data)
{
    size_t x; 
    size_t y;
    bool found_c = false, found_e = false, found_p = false;

    x = 0;
    y = 0;
    // Recorrer el mapa para encontrar C, E, y P
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
            x++;
        }
        y++;
    }
    // Comprobar si se encontraron todas las letras
    if (found_c == true && found_e == true && found_p == true)
        printf("Valid chars...\n");
    if (found_c != true && found_e != true && found_p != true)
        printf("Doesn't have 'C', 'E', 'P'\n");
}

void validating_rect(t_data *data)
{
    size_t y;
    y = 0;
   
    while(y < data->map_height)
    {
        if(ft_strlen(data->map[y]) != data->map_width)
        {
            printf("Map is not a rectangle\n");
            exit(1);
        }
        
        y++;
    }
    printf("Valid rectangle\n");
}