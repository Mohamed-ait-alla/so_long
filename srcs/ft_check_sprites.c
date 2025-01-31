/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_sprites.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-all <mait-all@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 21:07:30 by mait-all          #+#    #+#             */
/*   Updated: 2025/01/31 15:35:15 by mait-all         ###   ########.fr       */
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
	char	*file_set;
	char	*file_set_h;

	file_set = ft_memchr(file, '.', ft_strlen(file));
	file_set_h = ft_memchr(file, '/', ft_strlen(file)) + 1;
	if (!file_set || !file_set_h)
		return ;
	if ((file_set_h[0] == '.' && file_set_h[1] == 'b'
			&& file_set_h[2] == 'e' && file_set_h[3] == 'r')
		|| (file_set[1] != 'b' || file_set[2] != 'e' || file_set[3] != 'r'))
	{
		ft_printf("Error\n: Invalid map file extention!\n");
		exit(1);
	}
}
