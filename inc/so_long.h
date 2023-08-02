/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 12:19:56 by marvin            #+#    #+#             */
/*   Updated: 2023/08/02 20:21:13 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <stdbool.h>
# include "mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include "../inc/get_next_line.h"
# include "../src/libft/libft.h"
# include "../src/ft_printf/ft_printf.h"

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define RESET "\033[0m"

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
	size_t	initial_position_x;
	size_t	initial_position_y;
	int		player_mov;
	size_t	map_width;
	size_t	map_height;
}	t_data;

/* check_chars.c */
bool	all_chars(char character);
void	check_chars(t_data *data, bool *found_c, int *found_e, int *found_p);

/* check_path.c */
void	flood_fill(t_data *data, size_t x, size_t y);
void	check_path_not_found(t_data *data);

/* check_walls.c */
bool	check_walls_left_right(t_data *data, bool invalid_walls);
bool	check_walls_top_bottom(t_data *data, bool invalid_walls);

/* draw_objects.c */
void	ft_empty(t_data *data, t_img *img);
void	ft_wall(t_data *data, t_img *img);
void	ft_collectable(t_data *data, t_img *img);
void	ft_exit(t_data *data, t_img *img);
void	draw(t_data *data, t_img *img);

/* handle_and_windows.c */
int		handle_keypress(int key, t_data *data);
int		handle_esc_screen(t_data *data);
void	ft_mov_display(t_data *data, t_img *img);
void	creating_window(t_data *data, t_img *img);

/* init.c */
size_t	map_height(char **map);
void	init_data(t_data *data);
void	init_points(t_data *data);

/* move_player.c */
void	ft_move_initial(int key, t_data *data);
void	finish_game(t_data *data, t_img *img);

/* movements.c */
void	player_above_door(t_data *data, t_img *img, int player_x, int player_y);
void	move_up(int key, t_data *data);
void	move_left(int key, t_data *data);
void	move_down(int key, t_data *data);
void	move_right(int key, t_data *data);

/* read_map.c */
char	*read_map(char *filename);
char	**return_map(char *filename);

/* utils.c */
void	free_map(t_data *data);
void	arg_errors(int argc, char **argv);

/* validating_walls.c */
bool	check_walls_left_right(t_data *data, bool invalid_walls);
bool	check_walls_top_bottom(t_data *data, bool invalid_walls);
void	validating_walls(t_data *data);

/* validating_map.c */
void	validating_walls(t_data *data);
void	validating_chars(t_data *data);
void	validating_rect(t_data *data);
void	validating_path(t_data *data);
void	check_dotber(char *argv);

#endif