/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:35:55 by isromero          #+#    #+#             */
/*   Updated: 2022/10/20 12:34:23 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# define HEX_LOW "0123456789abcdef"
# define HEX_UP "0123456789ABCDEF"

int			ft_printf(char const *str, ...);
int			ft_print_conversions(va_list argptr, const char conversion);
int			ft_print_c(char c);
int			ft_print_s(char *s);
int			ft_print_p(unsigned long int n);
int			ft_print_i_and_d(int n);
int			ft_print_u(unsigned int n);
int			ft_print_x_low(unsigned int n);
int			ft_print_x_up(unsigned int n);
int			ft_print_perc(void);
#endif