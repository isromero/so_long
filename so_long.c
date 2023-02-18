/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 12:27:41 by marvin            #+#    #+#             */
/*   Updated: 2023/02/17 12:27:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void validating_chars(char **map, int number_lines);
void    validating_walls(char **map, int number_lines);

void    read_map(char *filename, static char **map)
{
    int     fd;
    char    *line;
    int     number_line;

    line = NULL;
    number_line = 0;
    fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        printf("Error al abrir el archivo\n");
        return ;
    }
    while(((line = get_next_line(fd))) != NULL) //Se seguirá ejecutando hasta que termine el archivo ya que gnl devuelve todo el rato una línea hasta el final
    {
        strcpy(map[number_line], line);
        free(line);
        number_line++;
    }
    validating_walls(map, number_line);
    validating_chars(map, number_line);
    close(fd);
}

void    validating_walls(char **map, int number_lines)
{
    int     len_x;
    int     x;
    int     y;
    int     i;

    len_x = strlen(map[0]);
    x = 0;
    y = 0;
    while(y < number_lines) 
    {
        if(strlen(map[y] != len_x)) //Si encontramos una línea con longitud diferente a la primera significa que no es rectangular
        {
            printf("Not rectangular\n");
            return ;
        }
        if (maps[y][0] != '1' || map[y][len_x - 1] != '1')
        {
            printf("Not walls on the left/right");
            return ;
        }
        y++;
    }
    while(x < len_x)
    {
        if (map[0][x] != '1' || map[number_lines - 1][x] != '1')
        {
            printf("Not walls on the top/bottom");
            return ;
        }
        x++;
    }
    printf("Valid walls...\n");
}

void validating_chars(char **map, int number_lines) 
{
    int x, y;
    int len_x = strlen(map[0]);
    bool found_c = false, found_e = false, found_p = false;

    x = 0;
    y = 0;
    // Recorrer el mapa para encontrar C, E, y P
    while (y < number_lines) 
    {
        while (x < len_x) 
        {
            if (map[y][x] == 'C') 
                found_c = true;
            else if (map[y][x] == 'E')
                found_e = true;
            else if (map[y][x] == 'P')
                found_p = true;
            x++;
        }
        y++;
    }
    // Comprobar si se encontraron todas las letras
    if (found_c && found_e && found_p)
        printf("Valid chars...\n");
    else
        printf("Doesn't have 'C', 'E', 'P'\n");
}

int main(int argc, char **argv)
{
    read_map(argv[2], argv);
    return (0);
}