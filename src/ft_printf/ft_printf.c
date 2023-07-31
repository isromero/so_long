/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:53:16 by isromero          #+#    #+#             */
/*   Updated: 2022/10/20 14:02:36 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_conversions(va_list argptr, const char conversion)
{
	size_t	length;

	length = 0;
	if (conversion == 'c')
		length += ft_print_c(va_arg(argptr, int));
	else if (conversion == 's')
		length += ft_print_s(va_arg(argptr, char *));
	else if (conversion == 'p')
	{
		length += write(1, "0x", 2);
		length += ft_print_p(va_arg(argptr, unsigned long int));
	}
	else if (conversion == 'd' || conversion == 'i')
		length += ft_print_i_and_d(va_arg(argptr, int));
	else if (conversion == 'u')
		length += ft_print_u(va_arg(argptr, unsigned int));
	else if (conversion == 'x')
		length += ft_print_x_low(va_arg(argptr, unsigned int));
	else if (conversion == 'X')
		length += ft_print_x_up(va_arg(argptr, unsigned int));
	else if (conversion == '%')
		length += ft_print_perc();
	return (length);
}

int	ft_printf(char const *str, ...)
{
	int		i;
	int		length;
	va_list	argptr;

	i = 0;
	length = 0;
	va_start(argptr, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			length += ft_print_conversions(argptr, str[i + 1]);
			i++;
		}
		else
			length += ft_print_c(str[i]);
		i++;
	}
	va_end(argptr);
	return (length);
}

/*int main(void)
{
	printf("%u", -10);
}*/
