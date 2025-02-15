/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_sprites.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-all <mait-all@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 21:07:30 by mait-all          #+#    #+#             */
/*   Updated: 2025/02/15 16:14:20 by mait-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_sprites(t_mlx_data *mlx)
{
	int	i;
	int	j;

	if (!mlx->sprites.black_wall || !mlx->sprites.exit
		|| !mlx->sprites.food || !mlx->sprites.wall)
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

void	check_file_extention(char *file)
{
	char	*file_ext;
	char	*file_ext_h;

	file_ext = ft_memchr(file, '.', ft_strlen(file));
	file_ext_h = ft_memchr(file, '/', ft_strlen(file));
	if (!file_ext_h)
	{
		ft_printf(RED "Error\n: Invalid path." RST);
		ft_printf(RED " Navigate to the 'maps' folder and choose a map.\n" RST);
		exit(1);
	}
	if (!file_ext || !file_ext_h
		|| (file_ext[1] != 'b' || file_ext[2] != 'e' || file_ext[3] != 'r')
		|| (file_ext_h[1] == '.' && file_ext_h[2] == 'b'
			&& file_ext_h[3] == 'e' && file_ext_h[4] == 'r'))
	{
		ft_printf(RED "Error\n: Invalid map file extention!\n" RST);
		exit(1);
	}
}
