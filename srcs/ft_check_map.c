/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-all <mait-all@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:30:19 by mait-all          #+#    #+#             */
/*   Updated: 2025/01/29 21:34:33 by mait-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char **map, int i) 
{
	ft_printf("map is not valid!\n");
	ft_free_map(map, i);
	exit(1);
}

void	check_file_extention(char *file)
{
	char	*file_set;
	char	*file_set_h;
	
	file_set = ft_memchr(file, '.', ft_strlen(file));
	file_set_h = ft_memchr(file, '/', ft_strlen(file)) + 1;
	if ((file_set_h[0] == '.' && file_set_h[1] == 'b' && file_set_h[2] == 'e' && file_set_h[3] == 'r') ||
	    (file_set[1] != 'b' || file_set[2] != 'e' || file_set[3] != 'r'))
	{
		printf("Invalid extention\n");
		exit(1);
	}
}

int	ft_open_fd(char *file)
{
	int	fd;
	fd = open(file, O_RDONLY);
	if (fd <= 0)
	{
		ft_printf("failed to open file descriptor\n");
		exit(1);
	}
	return (fd);
}

void	ft_check_error_map(char **map, t_frame frame)
{
	if ((frame.n_col - 1) * SIZE > 1920 || frame.n_row * SIZE > 1080)
	{
		ft_printf("map exceed the resolution of the screen\n");
		ft_error(map, frame.n_row);
	}
	if (!is_epc_in_map(map) || !is_map_rectangular(map) || !is_map_closed_by_walls(map) || !is_map_has_other_chars(map))
		ft_error(map, frame.n_row);
}

char	**ft_read_map(char *file, t_frame *frame)
{
	char	**map;
	int		i;
	int		fd;

	ft_calc_width_and_height(file, frame);
	map = (char **)malloc((frame->n_row + 1) * sizeof(char *));
	if (!map)
		return (NULL);
	fd = ft_open_fd(file);
	i = 0;
	while (i < frame->n_row)
	{
		map[i] = get_next_line(fd);
		if (!map[i])
			ft_free_map(map, i);
		i++;	
	}
	map[i] = NULL;
	get_next_line(-2);
	close(fd);
	return (map);
}

void	ft_calc_width_and_height(char *file, t_frame *frame)
{
	int		fd;
	int		count;
	char	*line;

	count = 0;
	fd = ft_open_fd(file);
	line = get_next_line(fd);
	if (!line)
	{
		ft_printf("map is empty\n");
		exit(1);
	}
	frame->n_col = ft_strlen(line);
	free(line);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		count++;
	}
	free(line);
	frame->n_row = count + 1;
}