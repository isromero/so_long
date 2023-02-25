/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 20:27:51 by marvin            #+#    #+#             */
/*   Updated: 2023/02/21 20:27:51 by marvin           ###   ########.fr       */
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
# if defined(__APPLE__)
#  include <key_macos.h>
# else
#  include <key_linux.h>
# endif

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

typedef struct s_map
{
    object_type_t type;
    int len_x;
} t_map;

#endif