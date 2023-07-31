/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:23:40 by isromero          #+#    #+#             */
/*   Updated: 2023/07/20 13:25:13 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_cnt_uint_n_10(unsigned long int n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	ft_print_u(unsigned int n)
{
	char	str;

	if (n <= 9)
	{
		str = n + '0';
		write(1, &str, 1);
	}
	else
	{
		ft_print_u(n / 10);
		ft_print_u(n % 10);
	}
	return (ft_cnt_uint_n_10(n));
}
