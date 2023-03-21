/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 17:54:38 by isromero          #+#    #+#             */
/*   Updated: 2022/09/22 17:00:50 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t					i;
	unsigned const char		*c;
	unsigned char			*p;

	i = 0;
	p = dst;
	c = src;
	if (p == NULL && c == NULL)
		return (NULL);
	while (i < n)
	{
		p[i] = c[i];
		i++;
	}
	return (dst);
}

/*int main ()
{
	char str1[] = "Geezz";
	char str2[] = "Qui";

	puts("str1 before memcpy ");
	puts(str1);

	memcpy (str1, str2, 2);

	puts("\nstr1 after memcpy ");
	puts(str1);
	ft_memcpy (str1, str2, 2);

	puts("\nstr1 after memcpy ");
	puts(str1);

	return 0;
}*/