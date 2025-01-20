/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_map_valid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-all <mait-all@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:36:39 by mait-all          #+#    #+#             */
/*   Updated: 2025/01/20 10:22:40 by mait-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_init(int *i, int *check_e, int *check_p, int *check_c)
{
	*i = 0;
	*check_e = 0;
	*check_p= 0;
	*check_c = 0;
}

int	check_epc_in_map(char **map)
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
	if (check_exit != 1 || check_player != 1 || check_collectible == 0)
		return (0);
	return (1);
}


