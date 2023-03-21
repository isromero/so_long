/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 20:00:19 by isromero          #+#    #+#             */
/*   Updated: 2022/09/25 12:27:51 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*p;
	char	*c;
	size_t	i;
	size_t	j;

	j = 0;
	i = 1;
	p = (char *)haystack;
	c = (char *)needle;
	if (!*needle)
		return (p);
	while (j < len && len != 0 && *p)
	{
		if (*p == *c)
		{
			while (c[i] == p[i] && c[i] && j + i < len)
				i++;
			if (!c[i])
				return (p);
		}
		p++;
		j++;
	}
	return (NULL);
}

/*int main(void) 
{
	char *searchingFor = "la";
	char *in = "la da\ndoo a da\nnow here comes the stack\nok there it was.\n";

    printf("found: %s\n", ft_strnstr(in, searchingFor, 5) ? "yes" : "no");
    printf("found: %s\n", ft_strnstr(in, searchingFor, 5) ? "yes" : "no");
    printf("found: %s\n", ft_strnstr(in, searchingFor, 5) ? "yes" : "no");
    return 0;
}*/