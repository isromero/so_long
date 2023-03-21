/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 12:19:56 by marvin            #+#    #+#             */
/*   Updated: 2023/03/21 19:03:35 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <mlx.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include "get_next_line.h"

#define RED_PIXEL 0xFF0000
#define GREEN_PIXEL 0xFF00
#define WHITE_PIXEL 0xFFFFFF

typedef struct s_img
{
    void	*mlx_img; //apunta a la imagen que se ha creado
	void	*wall;
	char	*addr; //puntero al 1er byte de la imagen en la memoria de la gráfica
	int		bpp; //bits por pixel
	int		line_len; //nº de bytes q ocupa cada línea de la imagen en la memoria de la gráfica
	int		endian; //orden en el que se almacenan bytes en la memoria de la gráfica
    int     img_width;
	int 	img_height;
} t_img;

typedef struct s_data
{
    void    *mlx_ptr;
    void    *win_ptr;
    int     current_img;
    t_img   *img;
   	char   **map;
    int     door_x;
    int     door_y;
    int     num_collectable_map;
    int     num_collectable;
	int		key;
    int     x;
    int     y;
    int     player_x;
    int     player_y;
	int		player_mov;
	int 	map_width;
	int 	map_height;
} t_data;

void init_data(t_data *data);
void init_points(t_data *data);


void    validating_walls(t_data *data);
void    validating_chars(t_data *data);
void    ft_empty(t_data *data, t_img *img);
void    ft_wall(t_data *data, t_img *img);
void    ft_collectable(t_data *data, t_img *img);
void    ft_exit(t_data *data, t_img *img);


void	ft_mov_display(t_data *data, t_img *img);


void    ft_initial(int key, t_data *data);


void    draw(int key, t_data *data, t_img *img);


int     handle_keypress(int key, t_data *data);
int     handle_esc_screen(t_data *data);


void    creating_window(int key, t_data *data, t_img *img);
void    so_long(int key, t_data *data, t_img *img);

int    number_lines(t_data *data);

#endif