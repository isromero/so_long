/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:47:17 by isromero          #+#    #+#             */
/*   Updated: 2023/03/22 17:33:49 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcat(char *dest, const char *src)
{
	int	a;
	int	i;

	a = 0;
	i = 0;
	while (dest[a] != '\0')
	{
		a++;
	}
	while (src[i] != '\0')
	{
		dest[a] = src[i];
		a++;
		i++;
	}
	dest[a] = '\0';
	return (dest);
}

static char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*p;

	if (!s1 || !s2)
		return (0);
	p = malloc(ft_strlen(s1) + (ft_strlen(s2) + 1));
	if (p)
	{
		ft_strcpy(p, s1);
		ft_strcat(p, s2);
	}
	return (p);
}

/*int main()
{
	char src[] = "Ldfgdfg";
	char dest[] = "Ugbg";

	printf("%s", ft_strjoin(dest, src));

	return 0;
}*/