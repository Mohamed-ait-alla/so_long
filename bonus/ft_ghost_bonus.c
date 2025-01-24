/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ghost_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-all <mait-all@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:31:44 by mait-all          #+#    #+#             */
/*   Updated: 2025/01/24 11:02:40 by mait-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_check_distance_with_ghosts(t_mlx_data *mlx, int P_new_pos_x, int P_new_pos_y)
{
	printf("P_new_pos_y=%d, P_new_pos_x=%d    g_pos_y=%d, g_pos_x=%d\n", P_new_pos_y, P_new_pos_x, mlx->ghosts[0].old_pos_y, mlx->ghosts[0].old_pos_x);
	int	i;
	i = 0;
	
	// if ((P_new_pos_x == mlx->ghost_pos_x) && (mlx->ghost_pos_y - 1 == P_new_pos_y))
	// 	printf("player is close up to ghost\n");
	// else if ((mlx->ghost_pos_x - 1 == P_new_pos_x) && (mlx->ghost_pos_y == P_new_pos_y))
	// 	return (0);
	// else if ((mlx->ghost_pos_x == P_new_pos_x) && (mlx->ghost_pos_y + 1 == P_new_pos_y))
	// 	printf("player is close down to ghost\n");
	// else if ((mlx->ghost_pos_x + 1 == P_new_pos_x) && (mlx->ghost_pos_y == P_new_pos_y))
	// 	printf("player is close right to ghost\n");
	// else if ((mlx->ghost_pos_x + 1 == P_new_pos_x) && (mlx->ghost_pos_y - 1 == P_new_pos_y))
	// 	printf("player is close up right diagonal to ghost\n");
	// else if ((mlx->ghost_pos_x - 1 == P_new_pos_x) && (mlx->ghost_pos_y - 1 == P_new_pos_y))
	// 	printf("player is close up left diagonal to ghost\n");
	// else if ((mlx->ghost_pos_x - 1 == P_new_pos_x) && (mlx->ghost_pos_y + 1 == P_new_pos_y))
	// 	printf("player is close down left diagonal to ghost\n");
	// else if ((mlx->ghost_pos_x + 1 == P_new_pos_x) && (mlx->ghost_pos_y + 1 == P_new_pos_y))
	// 	printf("player is close down right diagonal to ghost\n");
	// return (1);
	while (i < mlx->n_of_ghosts)
	{
		if ((abs(mlx->ghosts[i].old_pos_x - P_new_pos_x) + abs(mlx->ghosts[i].old_pos_y - P_new_pos_y)) == 0)
			ft_lose();
		if ((abs(mlx->ghosts[i].old_pos_x - P_new_pos_x) + abs(mlx->ghosts[i].old_pos_y - P_new_pos_y)) < 3)
			return (0);
		i++;	
	}
	
	return(1);
}