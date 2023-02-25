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

#include "so_long.h"
#include "get_next_line.h"

void    validating_chars(t_map **map, size_t number_line, size_t number_col);
void    validating_walls(t_map **map, size_t number_line, size_t number_col);
void    parse_objects(t_map **map, size_t number_line, size_t number_col);

void    read_map(char *filename)
{
    t_map **map;
    size_t     fd;
    char    *line;
    size_t  number_line;
    size_t  number_col;
    size_t     y;

    line = NULL;
    number_line = 0;
    y = 0;
    fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        printf("Error al abrir el archivo\n");
    }

    // Contamos el número de líneas en el archivo
    while ((line = get_next_line(fd)) != NULL)
    {
        number_col = strlen(line);
        number_line++;
        free(line);
    }

    //Alojamos memoria 
    map = malloc(number_line * sizeof(t_map *)); // Con esto alojamos a map[y][x] 
    while(y < number_line)
    {
        map[y] = malloc(number_col * sizeof(t_map));
        memset(map[y], 0, number_col * sizeof(t_map));
        y++;
    }
    close (fd);
    fd = open(filename, O_RDONLY);

    y = 0;
    while(((line = get_next_line(fd))) != NULL) //Se seguirá ejecutando hasta que termine el archivo ya que gnl devuelve todo el rato una línea hasta el final
    {
        for (int x = 0; x < number_col; x++) 
        {
            map[y][x].type = line[x];
        }
        free(line);
        y++;
    }
    close(fd);
    validating_walls(map, number_line, number_col);
    validating_chars(map, number_line, number_col);
    parse_objects(map, number_line, number_col);
}

void    validating_walls(t_map **map, size_t number_line, size_t number_col)
{
    size_t     x;
    size_t     y;

    x = 0;
    y = 0;
    while(y < number_line) 
    {
        if (map[y][0].type != '1')
        {
            printf("Not walls on the left\n");
            break ;
        }
        if (map[y][number_col - 1].type != '1')
        {
            printf("Not walls on the right\n");
            break ;
        }
        y++;
    }
    while(x < number_col)
    {
        if (map[0][x].type != '1' || map[number_line - 1][x].type != '1')
        {
            printf("Not walls on the top/bottom\n");
            break ;
        }
        x++;
    }
    printf("Valid walls...\n");
}

void validating_chars(t_map **map, size_t number_line, size_t number_col) 
{
    size_t x, y;
    bool found_c = false, found_e = false, found_p = false;

    x = 0;
    y = 0;
    // Recorrer el mapa para encontrar C, E, y P
    while (y < number_line) 
    {
        x = 0;
        while (x < number_col) 
        {
            if (map[y][x].type == 'C') 
                found_c = true;
            else if (map[y][x].type == 'E')
                found_e = true;
            else if (map[y][x].type == 'P')
                found_p = true;
            x++;
        }
        y++;
    }
    // Comprobar si se encontraron todas las letras
    if (found_c && found_e && found_p)
        printf("Valid chars...\n");
    if (found_c != true && found_e != true && found_p != true)
        printf("Doesn't have 'C', 'E', 'P'\n");
}

void    parse_objects(t_map **map, size_t number_line, size_t number_col)
{
    size_t x, y;

    x = 0;
    y = 0;
    // Recorrer el mapa para encontrar C, E, y P
    while (y < number_line) 
    {
        x = 0;
        while (x < number_col) 
        {
            if (map[y][x].type == '0')
            {
                map[y][x].type = EXIT;
                printf("%c", '0');
            }
            else if (map[y][x].type == '1')
            {
                map[y][x].type = WALL;
                printf("%c", '1');
            }
            else if (map[y][x].type == 'C')
            {
                map[y][x].type = COLLECTABLE;
                printf("%c", 'C');
            }
            else if (map[y][x].type == 'E')
            {
                map[y][x].type = EXIT;
                printf("%c", 'E');
            }
            else if (map[y][x].type == 'P')
            {
                map[y][x].type = INITIAL_POSITION;
                printf("%c", 'P');
            }
            x++;
        }
        y++;
        printf("\n");
    }
}

void	movements(t_player *player, int key)
{
    if (key == 'W')
        player->y--;
    if (key == 'A')
        player->x--;
    if (key == 'S')
        player->y++;
    if (key == 'D')
        player->x++;
}


int main(int argc, char **argv)
{
    read_map(argv[1]);
    void    *mlx_ptr;
    void    *win_ptr;
    void    *img;
    t_player    player;

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_windows(mlx_ptr, 800, 600, "so_long");
    mlx_loop(mlx_ptr);

    mlx_destroy_window(mlx_ptr, win_ptr);
    mlx_destroy_display(mlx_ptr);
    free(mlx_ptr);
    return (0);
}