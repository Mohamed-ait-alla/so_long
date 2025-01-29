/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-all <mait-all@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:34:43 by mait-all          #+#    #+#             */
/*   Updated: 2025/01/28 19:07:29 by mait-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_map(char **map, int i)
{
	while (i--)
		free(map[i]);
	free(map);
}

void	ft_free_sprites(t_mlx_data *mlx)
{
	int	i;
	int	j;
	
	if (mlx->sprites.black_wall)
		mlx_destroy_image(mlx->mlx_ptr, mlx->sprites.black_wall);
	if (mlx->sprites.wall)
		mlx_destroy_image(mlx->mlx_ptr, mlx->sprites.wall);
	if (mlx->sprites.exit)
		mlx_destroy_image(mlx->mlx_ptr, mlx->sprites.exit);
	if (mlx->sprites.food)
		mlx_destroy_image(mlx->mlx_ptr, mlx->sprites.food);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 3)
		{
			if (mlx->player_actions[i][j])
				mlx_destroy_image(mlx->mlx_ptr, mlx->player_actions[i][j]);
			j++;
		}
		i++;
	}
}