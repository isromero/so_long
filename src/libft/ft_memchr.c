/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 19:16:32 by isromero          #+#    #+#             */
/*   Updated: 2022/09/19 18:24:17 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	ch;
	size_t			i;

	p = (unsigned char *) s;
	ch = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		if (*p == ch)
			return (p);
		i++;
		p++;
	}
	return (0);
}

/*int main()
{
   char cadena[] = "Erase una vez...";
   char *puntero; 
 
   puntero = (char *)ft_memchr( cadena, 'a', 3 );
   printf( "%s\n", cadena); 
   printf( "%s\n", puntero ); 
 
   return 0;
}*/