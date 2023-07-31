/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:16:01 by isromero          #+#    #+#             */
/*   Updated: 2022/10/20 12:13:24 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_cnt_int_n_10(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	ft_print_i_and_d(int n)
{
	char	str;
	int		count;

	count = ft_cnt_int_n_10(n);
	if (n == -2147483648)
		return (ft_print_s("-2147483648"));
	if (n < 0)
	{
		ft_print_c('-');
		n *= -1;
	}
	if (n >= 0 && n <= 9)
	{
		str = n + '0';
		write(1, &str, 1);
	}
	else
	{
		ft_print_i_and_d(n / 10);
		ft_print_i_and_d(n % 10);
	}
	return (count);
}

int	ft_print_perc(void)
{
	return (write(1, "%", 1));
}
