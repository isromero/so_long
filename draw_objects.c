/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 22:31:11 by isromero          #+#    #+#             */
/*   Updated: 2023/03/22 19:00:00 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_empty(t_data *data, t_img *img)
{
    img->mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "img/empty.xpm", &img->img_width, &img->img_height);
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->mlx_img, data->x * 32, data->y * 32);
}

void    ft_wall(t_data *data, t_img *img)
{
    img->mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "img/walls.xpm", &img->img_width, &img->img_height);
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->mlx_img, data->x * 32, data->y * 32);
}

void    ft_collectable(t_data *data, t_img *img)
{
    img->mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "img/collectable.xpm", &img->img_width, &img->img_height);
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->mlx_img, data->x * 32, data->y * 32);
}

void    ft_exit(t_data *data, t_img *img)
{
    img->mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "img/exit_closed.xpm", &img->img_width, &img->img_height);
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->mlx_img, data->x * 32, data->y * 32);
}

void draw(int key, t_data *data, t_img *img)
{
	data->y = 0;
	data->x = 0;
    while(data->y < data->map_height)
    {
        data->x = 0;
        while(data->x < data->map_width)
        {
            if (data->map[data->y][data->x] == '0')
            {
                ft_empty(data, img);
                ft_printf("%c",'0');
            }
            else if (data->map[data->y][data->x] == '1')
            {
                ft_wall(data, img);
                ft_printf("%c",'1');
            }
            else if (data->map[data->y][data->x] == 'C')
            {
                ft_printf("%c",'C');
                ft_collectable(data, img);
            }
            else if (data->map[data->y][data->x] == 'P')
            {
                data->player_y = data->y;
                data->player_x = data->x;
                ft_move_initial(key, data);
                ft_printf("%c",'P');
            }
            else if (data->map[data->y][data->x] == 'E')
            {
                data->door_x = data->x;
                data->door_y = data->y;
                ft_exit(data, img);
                ft_printf("%c",'E');
            }
            data->x++;
        }
        data->y++;
        ft_printf("\n");
    }
}