/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ghost_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-all <mait-all@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:31:44 by mait-all          #+#    #+#             */
/*   Updated: 2025/01/22 10:21:10 by mait-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_check_distance_with_ghosts(t_mlx_data *mlx, int P_new_pos_x, int P_new_pos_y)
{
	if ((P_new_pos_x == mlx->ghost_pos_x) && (mlx->ghost_pos_y - 1 == P_new_pos_y))
		printf("player is close up to ghost\n");
	else if ((mlx->ghost_pos_x - 1 == P_new_pos_x) && (mlx->ghost_pos_y == P_new_pos_y))
		printf("player is close left to ghost\n");	
	else if ((mlx->ghost_pos_x == P_new_pos_x) && (mlx->ghost_pos_y + 1 == P_new_pos_y))
		printf("player is close down to ghost\n");
	else if ((mlx->ghost_pos_x + 1 == P_new_pos_x) && (mlx->ghost_pos_y == P_new_pos_y))
		printf("player is close right to ghost\n");
	else if ((mlx->ghost_pos_x + 1 == P_new_pos_x) && (mlx->ghost_pos_y - 1 == P_new_pos_y))
		printf("player is close up right diagonal to ghost\n");
	else if ((mlx->ghost_pos_x - 1 == P_new_pos_x) && (mlx->ghost_pos_y - 1 == P_new_pos_y))
		printf("player is close up left diagonal to ghost\n");
	else if ((mlx->ghost_pos_x - 1 == P_new_pos_x) && (mlx->ghost_pos_y + 1 == P_new_pos_y))
		printf("player is close down left diagonal to ghost\n");
	else if ((mlx->ghost_pos_x + 1 == P_new_pos_x) && (mlx->ghost_pos_y + 1 == P_new_pos_y))
		printf("player is close down right diagonal to ghost\n");
	
	
	return (0);
}