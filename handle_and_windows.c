/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_and_windows.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 22:32:46 by isromero          #+#    #+#             */
/*   Updated: 2023/03/23 15:39:59 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_mov_display(t_data *data, t_img *img)
{
    size_t i;
    i = 0;

    img->mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./img/empty.xpm", &img->img_width, &img->img_height);
    while (i < (32 * data->map_width))
    {
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->mlx_img, i, data->map_height * 32);
        i += 32;
    }
   	mlx_string_put(data->mlx_ptr, data->win_ptr,
		data->map_width / 2, data->map_height * 34, 0xff0000,
		"MOVEMENTS ");
    mlx_string_put(data->mlx_ptr, data->win_ptr,
		data->map_width * 30, data->map_height * 34, 0xff0000,
		ft_itoa(data->player_mov));
}

int	handle_keypress(int key, t_data *data)
{
    if (!data) //meter exit
        ft_printf("Error: data es un puntero nulo\n");
    if (!data->map)
        ft_printf("Error: data->map es un puntero nulo\n");
    if (key == 53 || key == 9) //XK_Escape, 59
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		exit (1);
	}
	ft_move_initial(key, data);
    return (0);
}
int handle_esc_screen(t_data *data)
{
    mlx_destroy_window(data->mlx_ptr, data->win_ptr);
    exit(0);
    return(0);
}

void    creating_window(int key, t_data *data, t_img *img)
{
    int width = 0;
    width = data->map_width * 32;
    int height = 0;
    height = data->map_height * 32;
    data->mlx_ptr = mlx_init();
    data->win_ptr = mlx_new_window(data->mlx_ptr, width, height + 32, "so_long");
    img->mlx_img = mlx_new_image(data->mlx_ptr, width, height); //crea una imagen en la memoria de video de la pantalla
    img->addr = mlx_get_data_addr(img->mlx_img, &img->bpp, &img->line_len, &img->endian); //se devuelve un puntero al primer byte de la imagen donde se usa para escribir en ella pixel por pixel
	init_points(data);
    draw(key, data, img);
    mlx_key_hook(data->win_ptr, handle_keypress, data);
    mlx_hook(data->win_ptr, 17, 1L<<0, handle_esc_screen, data);
    mlx_loop(data->mlx_ptr);

    //exit(0);

    // mlx_destroy_image(data->mlx_ptr, img->mlx_img);
    // mlx_destroy_display(data->mlx_ptr);
    // free(data->mlx_ptr);
}