/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_sprites_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-all <mait-all@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 09:57:41 by mait-all          #+#    #+#             */
/*   Updated: 2025/02/15 15:02:26 by mait-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static	int	ft_check_ghost_sprites(t_mlx_data *mlx)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (!mlx->sprites.ghost_up[i] || !mlx->sprites.ghost_down[i]
			|| !mlx->sprites.ghost_right[i] || !mlx->sprites.ghost_left[i])
			return (0);
		i++;
	}
	return (1);
}

static	int	ft_check_player_dying_sprites(t_mlx_data *mlx)
{
	int	i;

	i = 0;
	while (i < 11)
	{
		if (!mlx->player_dying[i])
			return (0);
		i++;
	}
	return (1);
}

static	int	ft_check_player_actions_sprites(t_mlx_data *mlx)
{
	int	i;
	int	j;

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

int	ft_check_sprites(t_mlx_data *mlx)
{
	if (!mlx->sprites.black_wall || !mlx->sprites.exit
		|| !mlx->sprites.food || !mlx->sprites.wall
		|| !ft_check_player_actions_sprites(mlx)
		|| !ft_check_player_dying_sprites(mlx)
		|| !ft_check_ghost_sprites(mlx))
		return (0);
	return (1);
}

void	check_file_extention(char *file)
{
	char	*file_ext;
	char	*file_ext_h;

	file_ext = ft_memchr(file, '.', ft_strlen(file));
	file_ext_h = ft_memchr(file, '/', ft_strlen(file)) + 1;
	if (!file_ext || !file_ext_h || (file_ext_h[0] == '.' && file_ext_h[1] == 'b'
			&& file_ext_h[2] == 'e' && file_ext_h[3] == 'r')
		|| (file_ext[1] != 'b' || file_ext[2] != 'e' || file_ext[3] != 'r') )
	{
		ft_printf(RED "Error\n: Invalid map file extention!\n" RESET);
		exit(1);
	}
}
