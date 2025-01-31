/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-all <mait-all@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:30:19 by mait-all          #+#    #+#             */
/*   Updated: 2025/01/31 19:00:16 by mait-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_error(char **map, int i, int flag)
{
	char	*flag_msg[4];

	flag_msg[0] = ": One letter in these (EPC) is messed in map!\n";
	flag_msg[1] = ": Map is not rectangular!\n";
	flag_msg[2] = ": Map is not closed by walls!\n";
	flag_msg[3] = ": Map has a not valid character!\n";
	ft_printf("Error\n%s", flag_msg[flag]);
	ft_free_map(map, i);
	exit(1);
}

int	ft_open_fd(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd <= 0)
	{
		ft_printf("Error\n: Failed to open file descriptor\n");
		exit(1);
	}
	return (fd);
}

void	ft_check_error_map(char **map, t_frame frame)
{
	int	flag;

	flag = -1;
	if ((frame.n_col - 1) * SIZE > 1920 || frame.n_row * SIZE > 1080)
	{
		ft_printf("Error\n: Map exceeds the resolution of the screen\n");
		ft_error(map, frame.n_row, flag);
	}
	if (!is_epc_in_map(map) || !is_map_rectangular(map)
		|| !is_map_closed_by_walls(map, frame) || !is_map_has_other_chars(map))
	{
		if (!is_epc_in_map(map))
			flag = 0;
		if (!is_map_rectangular(map))
			flag = 1;
		if (!is_map_closed_by_walls(map, frame))
			flag = 2;
		if (!is_map_has_other_chars(map))
			flag = 3;
		ft_error(map, frame.n_row, flag);
	}
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
		ft_printf("Error\n: Map is empty!\n");
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