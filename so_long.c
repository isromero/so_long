/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 12:27:41 by marvin            #+#    #+#             */
/*   Updated: 2023/02/17 12:27:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void   leak_check(void)
{
    system("leaks so_long");
}

char    **just_read_and_info(char *filename)
{
    int     fd;
    char    *line;
    char    *joined_lines;
    char    *trimmed_line;

    char    **result;

    line = NULL;
    joined_lines = NULL;
    fd = open(filename, O_RDONLY);
    if (fd < 0)
        exit(1);
    while ((line = get_next_line(fd)))
    {
        if (line[0] == '\n')
            break ;
        trimmed_line = ft_strtrim(line, "\n\t\r\f\v");
        joined_lines = ft_strjoin(joined_lines, trimmed_line);
		joined_lines = ft_strjoin(joined_lines, "\n");
        free(line);
        free(trimmed_line);
    }
    close(fd);
    if (!joined_lines || joined_lines[0] == '\0')
        exit(1);
    result = ft_split(joined_lines, '\n');
    free(joined_lines);
    return (result);
}

void leaks()
{
	system("leaks so_long"); 
}

void	free_map(t_data *data)
{
	int	i;

	i = 0;
	while(data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
}

int main(int argc, char **argv)
{
	atexit(leak_check);
	int		key;
	t_data	data;
	t_img	img;
	key = 0;

	if(argc == 1)
    {
		ft_printf("no arguments\n");
		exit(1);
    }
	if(argc > 2)
    {
		ft_printf("the first file is the valid one\n");
		exit(1);
    }
	data.map = just_read_and_info(argv[1]);

	init_data(&data);
	check_dotber(argv[1]);
	validating_rect(&data);
    validating_walls(&data);
	validating_chars(&data);
    find_path(&data);
    free_map(&data);
    data.map = just_read_and_info(argv[1]);
	creating_window(key, &data, &img);
	free_map(&data);
	return (0);
}
