/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 20:53:42 by isromero          #+#    #+#             */
/*   Updated: 2023/07/31 20:53:56 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	free_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
}

void	arg_errors(int argc, char **argv)
{
	int		file;

	file = open(argv[1], O_RDONLY);
	if (file == -1)
	{
		ft_printf(RED "Error: File '%s' not found\n" RESET, argv[1]);
		exit(1);
	}
	if (argc == 1)
	{
		ft_printf(RED "Error: Not valid arguments\n" RESET);
		ft_printf(RED "Try: [./so_long] [maps/.ber]\n" RESET);
		exit(1);
	}
	if (argc > 2)
	{
		ft_printf(RED "Error: The first file is the valid one\n" RESET);
		exit(1);
	}
}
