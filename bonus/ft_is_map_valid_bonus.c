/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_map_valid_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-all <mait-all@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:36:39 by mait-all          #+#    #+#             */
/*   Updated: 2025/02/01 09:42:20 by mait-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	ft_init(int *i, int *check_e, int *check_p, int *check_c)
{
	*i = 0;
	*check_e = 0;
	*check_p = 0;
	*check_c = 0;
}

int	is_epc_in_map(char **map)
{
	int	i;
	int	j;
	int	check_exit;
	int	check_player;
	int	check_collectible;

	ft_init(&i, &check_exit, &check_player, &check_collectible);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				check_exit++;
			else if (map[i][j] == 'P')
				check_player++;
			else if (map[i][j] == 'C')
				check_collectible++;
			j++;
		}
		i++;
	}
	if (check_exit != 1 || check_player != 1 || !check_collectible)
		return (0);
	return (1);
}

int	is_map_rectangular(char **map)
{
	int	first_row_len;
	int	i;

	first_row_len = ft_strlen(map[0]) - 1;
	i = 1;
	while (map[i])
	{
		if (map[i][ft_strlen(map[i]) - 1] != '\n')
		{
			if ((int)ft_strlen(map[i]) != first_row_len)
				return (0);
			i++;
		}
		else if ((int)ft_strlen(map[i]) - 1 != first_row_len)
			return (0);
		else
			i++;
	}
	return (1);
}

int	is_map_closed_by_walls(char **map, t_frame frame)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] != '\n')
		{
			if ((i == 0 && map[i][j] != '1')
				|| (i == (frame.n_row - 1) && map[i][j] != '1'))
				return (0);
			else if ((j == 0 && map[i][j] != '1')
				|| (j == (frame.n_col - 2) && map[i][j] != '1'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_map_has_other_chars(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] != '\n')
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'C'
				&& map[i][j] != 'E' && map[i][j] != 'P' && map[i][j] != 'G')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
