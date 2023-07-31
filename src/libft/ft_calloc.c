/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 18:17:05 by isromero          #+#    #+#             */
/*   Updated: 2022/09/30 18:00:03 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*a;
	size_t	i;

	i = 0;
	if (size > 2147483647 || count > 2147483647)
		return (0);
	a = malloc(count * size);
	if (!a)
		return (0);
	while (i < size * count)
	{
		a[i] = 0;
		i++;
	}
	return (a);
}

/*int main(void)
{
    int *p1 = ft_calloc(4, sizeof(int));
    int *p2 = ft_calloc(1, sizeof(int[4]));
    int *p3 = ft_calloc(4, sizeof *p3);     
 
    if(p2) {
        for(int n=0; n<4; ++n)
            printf("p2[%d] == %d\n", n, p2[n]);
    }
 
    free(p1);
    free(p2);
    free(p3);
}*/