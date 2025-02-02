/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-all <mait-all@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:08:45 by mait-all          #+#    #+#             */
/*   Updated: 2025/02/02 17:59:36 by mait-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_get_pos_of_p(t_mlx_data *mlx)
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

static void	flood_fill(t_mlx_data *mlx, int x, int y)
{
	if (y < 0 || x < 0 || x > (mlx->c_map_len - 2) || y > mlx->r_map_len)
		return ;
	if (mlx->map[y][x] == '1' || mlx->copy_map[y][x] == 'V')
		return ;
	if (mlx->map[y][x] == 'P' || mlx->map[y][x] == 'C'
		|| mlx->map[y][x] == '0' || mlx->map[y][x] == 'E')
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

static	void	ft_generate_a_copied_map(t_mlx_data *mlx, t_frame frame)
{
	int	i;

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
}

static void	ft_is_reachable(t_mlx_data *mlx, int i, int j)
{
	if (mlx->map[i][j] == 'C' && mlx->copy_map[i][j] != 'V')
	{
		ft_printf(RED "Error\n: can't reach a collectible!\n" RESET);
		ft_free_map(mlx->copy_map, mlx->r_map_len);
		ft_free_map(mlx->map, mlx->r_map_len);
		exit(1);
	}
	if (mlx->map[i][j] == 'E' && mlx->copy_map[i][j] != 'V')
	{
		ft_printf(RED "Error\n: can't reach exit!\n" RESET);
		ft_free_map(mlx->copy_map, mlx->r_map_len);
		ft_free_map(mlx->map, mlx->r_map_len);
		exit(1);
	}
}

void	ft_check_path(t_mlx_data *mlx, t_frame frame)
{
	int	i;
	int	j;

	ft_generate_a_copied_map(mlx, frame);
	flood_fill(mlx, mlx->player_pos_x, mlx->player_pos_y);
	i = 0;
	while (mlx->map[i])
	{
		j = 0;
		while (mlx->map[i][j] && mlx->map[i][j] != '\n')
		{
			ft_is_reachable(mlx, i, j);
			j++;
		}
		i++;
	}
	ft_free_map(mlx->copy_map, i);
}
