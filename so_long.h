/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-all <mait-all@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:02:20 by mait-all          #+#    #+#             */
/*   Updated: 2025/01/13 15:39:00 by mait-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
#define SIZE 32
#include <stdio.h> // we don't this header when we gonna push this shit 
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "./minilibx-linux/mlx.h"
#include "./get_next_line/get_next_line.h"
#include <X11/keysym.h>
typedef struct s_mlx_data
{
	void	*mlx_ptr;
	void	*mlx_window;
}	t_mlx_data;

typedef struct  s_img_data
{
	void	*img;
}	t_img_data;

typedef struct s_frame
{
	int	n_col;
	int	n_row;
}	t_frame;

void	ft_calc_width_and_height(char	*file, t_frame *frame);
void	ft_init_game(char *file, t_mlx_data *mlx);
#endif