/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_sprites.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-all <mait-all@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 21:07:30 by mait-all          #+#    #+#             */
/*   Updated: 2025/01/27 21:15:01 by mait-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_sprites(t_mlx_data *mlx)
{
	int	i;
	int	j;
	
	if (!mlx->sprites.black_wall || !mlx->sprites.exit || !mlx->sprites.food || !mlx->sprites.wall)
		return (0);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 3)
		{
			if (!mlx->player_actions[i][j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}