/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-all <mait-all@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:30:19 by mait-all          #+#    #+#             */
/*   Updated: 2025/01/15 10:38:09 by mait-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_free_map(char **map, int i)
{
	while (i--)
		free(map[i]);
	free(map);
}

void	ft_error() 
{
	write(2, "Error\n", 6);
	exit(1);
}

int	ft_open_fd(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd <= 0)
		printf("failed to open file descriptor\n");
	return (fd);
}

void	ft_check_error_map(char **map)
{
	int	i;
	int	j;
	int	check;
	
	i = 0;
	check = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				check++;
			j++;
		}
		i++;
	}
	if (check != 1)
		ft_error();
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
	return (map);
}

void	ft_calc_width_and_height(char	*file, t_frame *frame)
{
	int	fd;
	int	count;

	count = 0;
	fd = ft_open_fd(file);
	frame->n_col = ft_strlen(get_next_line(fd)) - 1;
	while (get_next_line(fd))
		count++;
	frame->n_row = count + 1;
}