/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-all <mait-all@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:48:59 by mait-all          #+#    #+#             */
/*   Updated: 2025/01/13 16:29:58 by mait-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_game(char *file, t_mlx_data *mlx)
{
	t_img_data	img;
	char		*col;
	int			fd;
	int			i;
	int			j;
	int			width;
	int			hight;

	img.img  = mlx_xpm_file_to_image(mlx->mlx_ptr, "./textures/wall.xpm", &width, &hight);
	fd = open(file, O_RDONLY);
	i = 1;
	while (i)
	{
		col = get_next_line(fd);
		if (!col)
			break;
		j = 0;
		while (col[j] != '\n' && col[j])
		{
			if (col[j] == '1')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window, img.img, j * SIZE,(i - 1) * SIZE);
			j++;		
		}
		i++;
	}
}