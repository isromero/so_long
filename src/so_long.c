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

#include "../inc/so_long.h"

// Incluir error de mapa no encontrado???
// Incluir error de si hay más de un Player

// void leaks()
// {
// 	system("leaks so_long"); 
// }

int	main(int argc, char **argv)
{
	// atexit(leak_check);
	t_data	data;
	t_img	img;

	arg_errors(argc, argv);
	data.map = return_map(argv[1]);
	init_data(&data);
	check_dotber(argv[1]);
	validating_rect(&data);
	validating_walls(&data);
	validating_chars(&data);
	validating_path(&data);
	free_map(&data);
	data.map = return_map(argv[1]);
	init_data(&data);
	creating_window(&data, &img);
	free_map(&data);
	return (0);
}
