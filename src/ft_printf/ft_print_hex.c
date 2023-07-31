/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:45:31 by isromero          #+#    #+#             */
/*   Updated: 2023/07/20 13:25:38 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_cnt_uint_16(unsigned long int n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

int	ft_print_p(unsigned long int n)
{
	char	str;

	if (n < 10)
	{
		str = n + '0';
		write(1, &str, 1);
	}
	else if (n > 9 && n < 16)
	{
		write(1, &"0123456789abcdef"[n % 16], 1);
	}
	else
	{
		ft_print_p(n / 16);
		ft_print_p(n % 16);
	}
	return (ft_cnt_uint_16(n));
}

int	ft_print_x_low(unsigned int n)
{
	char	str;

	if (n < 10)
	{
		str = n + '0';
		write(1, &str, 1);
	}
	else if (n > 9 && n < 16)
	{
		write(1, &HEX_LOW[n % 16], 1);
	}
	else
	{
		ft_print_x_low(n / 16);
		ft_print_x_low(n % 16);
	}
	return (ft_cnt_uint_16(n));
}

int	ft_print_x_up(unsigned int n)
{
	char	str;

	if (n <= 9)
	{
		str = n + '0';
		write(1, &str, 1);
	}
	else if (n > 9 && n < 16)
	{
		write(1, &HEX_UP[n % 16], 1);
	}
	else
	{
		ft_print_x_up(n / 16);
		ft_print_x_up(n % 16);
	}
	return (ft_cnt_uint_16(n));
}
