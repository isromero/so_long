/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 20:53:21 by isromero          #+#    #+#             */
/*   Updated: 2023/07/31 20:55:22 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char	*read_map(char *filename)
{
	int		fd;
	char	*line;
	char	*joined_lines;
	char	*trimmed_line;

	line = NULL;
	joined_lines = NULL;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit(1);
	line = get_next_line(fd);
	while (line && line[0] != '\n')
	{
		trimmed_line = ft_strtrim(line, "\n\t\r\f\v");
		joined_lines = ft_strjoin(joined_lines, trimmed_line);
		joined_lines = ft_strjoin(joined_lines, "\n");
		free(line);
		free(trimmed_line);
		line = get_next_line(fd);
	}
	close(fd);
	return (joined_lines);
}

char	**return_map(char *filename)
{
	char	*joined_lines;
	char	**result;

	joined_lines = read_map(filename);
	if (!joined_lines || joined_lines[0] == '\0')
		exit(1);
	result = ft_split(joined_lines, '\n');
	free(joined_lines);
	return (result);
}
