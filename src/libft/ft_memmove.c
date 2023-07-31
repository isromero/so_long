/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 20:12:07 by isromero          #+#    #+#             */
/*   Updated: 2022/09/22 17:50:57 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*p;
	unsigned char	*c;

	i = 0;
	p = (unsigned char *) src;
	c = (unsigned char *) dst;
	if (p == NULL && c == NULL)
		return (NULL);
	else if (c > p)
		while (len-- > 0)
			c[len] = p[len];
	else
	{
		while (i < len)
		{
			c[i] = p[i];
			i++;
		}
	}
	return (dst);
}

/*int main ()
{
	char str1[] = "Geezz";
	char str2[] = "Qui";

	puts("str1 before memcpy ");
	puts(str1);

	Copies contents of str2 to str1
	memmove (str1, str2, 2);

	puts("\nstr1 after memcpy ");
	puts(str1);

	ft_memmove (str1, str2, 2);

	puts("\nstr1 after memcpy ");
	puts(str1);
	return 0;
}*/