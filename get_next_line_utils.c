/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:14:33 by isromero          #+#    #+#             */
/*   Updated: 2022/10/17 13:32:09 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	count;

	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*p;
	size_t	j;
	size_t	i;

	j = 0;
	i = 0;
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	p = malloc(ft_strlen(s1) + (ft_strlen(s2) + 1));
	if (!p)
		return (NULL);
	while(s1[i] != '\0')
	{
		p[i] = s1[i];
		i++;
	}
	while(s2[j] != '\0')
		p[i++] = s2[j++];
	p[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free (s1);
	return (p);
}