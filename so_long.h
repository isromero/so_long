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
#include "get_next_line.h"

typedef struct s_data 
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
} t_data;

typedef enum object_type {
    EMPTY,
    WALL,
    COLLECTABLE,
    EXIT,
    INITIAL_POSITION
} object_type_t;

typedef struct s_player
{
    int x;
    int y;
} t_player;


typedef struct s_map
{
    object_type_t type;
    int len_x;
} t_map;

#endif