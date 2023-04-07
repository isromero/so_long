/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 12:19:56 by marvin            #+#    #+#             */
/*   Updated: 2023/04/07 19:01:00 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <stdbool.h>
# include <mlx.h>
// # include <X11/X.h>
// # include <X11/keysym.h>
# include "get_next_line.h"
# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"

typedef struct s_img
{
	void	*mlx_img;
	void	*wall;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		img_width;
	int		img_height;
}	t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		current_img;
	t_img	*img;
	char	**map;
	size_t	door_x;
	size_t	door_y;
	int		num_collectable_map;
	int		num_collectable;
	int		key;
	size_t	x;
	size_t	y;
	int		player_x;
	int		player_y;
    size_t  initial_position_x;
    size_t  initial_position_y;
	int		player_mov;
	size_t	map_width;
	size_t	map_height;
}	t_data;

/*so_long.c*/

/*init.c*/
size_t	map_height(char **map);
void	init_data(t_data *data);
void	init_points(t_data *data);

/*movements.c*/
void	move_up(int key, t_data *data);
void	move_left(int key, t_data *data);
void	move_down(int key, t_data *data);
void	move_right(int key, t_data *data);
void	ft_move_initial(int key, t_data *data);

/*handle_and_windows.c*/
int		handle_keypress(int key, t_data *data);
int		handle_esc_screen(t_data *data);
void	creating_window(int key, t_data *data, t_img *img);

/*draw_objects.c*/
void	ft_empty(t_data *data, t_img *img);
void	ft_wall(t_data *data, t_img *img);
void	ft_collectable(t_data *data, t_img *img);
void	ft_exit(t_data *data, t_img *img);
void    ft_initial(t_data *data, t_img *img);
void	draw(int key, t_data *data, t_img *img);

/*validating_map.c*/
void	validating_walls(t_data *data);
void	validating_chars(t_data *data);
void	validating_rect(t_data *data);
void	find_path(t_data *data);
void	check_dotber(char *argv);
void    flood_fill(t_data *data, size_t x, size_t y);


#endif