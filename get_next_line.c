/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:11:22 by isromero          #+#    #+#             */
/*   Updated: 2022/10/19 12:10:01 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_the_line(char *stash)
{
	char	*str;
	int		i;

	i = 0;
	if (!stash[i])
		return (0);
	while(stash[i] && stash[i] != '\n')
		i++;
	str = malloc(sizeof(char) * (i + 2));
	if (!str)
		return (0);
	i = 0;
	while(stash[i] && stash[i] != '\n')
	{
		str[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		str[i] = stash[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*get_the_next(char *stash)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(stash) - i) + 1);
	if (!str)
		return (0);
	i++;
	while (stash[i])
	{
		str[j] = stash[i];
		i++;
		j++;
	}
	str[j] = '\0';
	free(stash);
	return (str);
}

char	*ft_read(int fd, char *stash)
{
	int		byte;
	char	*line;

	line = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!line)
		return (0);
	byte = 1;
	while(!ft_strchr(stash, '\n') && byte != 0) 
	{
		byte = read(fd, line, BUFFER_SIZE);
		if (byte == -1)
		{
			free(line);
			return (NULL);
		}
		line[byte] = '\0';
		stash = ft_strjoin(stash, line);
	}
	free(line);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	stash = ft_read(fd, stash);
	if (!stash)
		return (0);
	line = get_the_line(stash);
	stash = get_the_next(stash);
	return (line);
}

/*int main(void)
{
    int     fd;
	
    fd = open("fichier.txt", O_RDONLY);

    if (fd < 3 && fd != 0)
        return (-1);

    printf("%d\n", fd);
    printf("%s", get_next_line(fd));
    return (0);
}*/