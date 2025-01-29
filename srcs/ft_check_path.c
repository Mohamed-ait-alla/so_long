/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-all <mait-all@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:08:45 by mait-all          #+#    #+#             */
/*   Updated: 2025/01/29 21:48:37 by mait-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_get_pos_of_p(t_mlx_data *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (mlx->map[i])
	{
		j = 0;
		while (mlx->map[i][j] && mlx->map[i][j] != '\n')
		{
			if (mlx->map[i][j] == 'P')
			{
				mlx->player_pos_x = j;
				mlx->player_pos_y = i;
			}
			j++;
		}
		i++;
	}
}

void	flood_fill(t_mlx_data *mlx, int x, int y)
{
	// printf("y = %d, x = %d\n", y, x);
	if (mlx->map[y][x] == '1' || mlx->copy_map[y][x] == 'V')
		return ;
	if (mlx->map[y][x] == 'P' || mlx->map[y][x] == 'C' || mlx->map[y][x] == '0' || mlx->map[y][x] == 'E')
	{
		if (mlx->map[y][x] == 'E')
		{
			mlx->copy_map[y][x] = 'V';
			return ;
		}
		mlx->copy_map[y][x] = 'V';
	}
	flood_fill(mlx, x + 1, y);
	flood_fill(mlx, x - 1, y);
	flood_fill(mlx, x, y + 1);
	flood_fill(mlx, x, y - 1);
}

void	ft_check_path(t_mlx_data *mlx, t_frame frame)
{
	int	i;
	int	j;

	i = 0;
	mlx->copy_map = malloc((frame.n_row + 1) * sizeof(char *));
	if (!mlx->copy_map)
		return ;
	while (i < frame.n_row)
	{
		mlx->copy_map[i] = malloc((frame.n_col - 1) * sizeof(char));
		if (!mlx->copy_map[i])
		{
			ft_free_map(mlx->copy_map, i);
			return ;
		}
		ft_memset(mlx->copy_map[i], 'N', frame.n_col - 1);
		i++;
	}
	ft_get_pos_of_p(mlx);
	flood_fill(mlx, mlx->player_pos_x, mlx->player_pos_y);
	i = 0;
	while (mlx->map[i])
	{
		j = 0;
		while (mlx->map[i][j] && mlx->map[i][j] != '\n')
		{
			if (mlx->map[i][j] == 'C' && mlx->copy_map[i][j] != 'V')
			{
				ft_printf("Error\n: can't reach a collectible\n");
				ft_free_map(mlx->copy_map, frame.n_row);
				ft_free_map(mlx->map, mlx->map_len);
				exit(1);
			}
			if (mlx->map[i][j] == 'E' && mlx->copy_map[i][j] != 'V')
			{
				ft_printf("Error\n: can't reach exit\n");
				ft_free_map(mlx->copy_map, frame.n_row);
				ft_free_map(mlx->map, mlx->map_len);
				exit(1);
			}
			j++;		
		}
		i++;
	}
	ft_free_map(mlx->copy_map, i);
	ft_free_map(mlx->map, mlx->map_len);
}