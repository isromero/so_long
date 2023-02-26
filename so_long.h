/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 12:19:56 by marvin            #+#    #+#             */
/*   Updated: 2023/02/25 12:19:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "mlx.h"
#include <X11/X.h>
#include <X11/keysym.h>
#include "get_next_line.h"

#define RED_PIXEL 0xFF0000
#define GREEN_PIXEL 0xFF00
#define WHITE_PIXEL 0xFFFFFF

typedef enum object_type {
    EMPTY,
    WALL,
    COLLECTABLE,
    EXIT,
    INITIAL_POSITION
} object_type_t;

typedef struct s_data
{
    void    *mlx_ptr;
    void    *win_ptr;
    int     x;
    int     y;
} t_data;


typedef struct s_map
{
    object_type_t type;
    int len_x;
} t_map;

#endif