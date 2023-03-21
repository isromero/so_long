/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 16:53:16 by isromero          #+#    #+#             */
/*   Updated: 2022/09/29 12:54:20 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		n;
	char	*p;

	i = 0;
	n = ft_strlen(s1);
	p = malloc(sizeof(char) * (n + 1));
	if (!p)
		return (NULL);
	while (i <= n)
	{
		p[i] = s1[i];
		i++;
	}
	return (p);
}

/*int main()
{
    char source[] = "GeeksForGeeks";
 
    // A copy of source is created dynamically
    // and pointer to copy is returned.
    char* target = strdup(source);
 
    printf("%s", target);
    return 0;
}*/