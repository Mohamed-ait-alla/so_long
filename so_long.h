/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-all <mait-all@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:02:20 by mait-all          #+#    #+#             */
/*   Updated: 2025/01/12 12:22:50 by mait-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
#include <stdio.h> // we don't this header when we gonna push this shit 
#include <stdlib.h>
#include "./minilibx-linux/mlx.h"
#include <X11/keysym.h>
typedef struct s_mlx_data
{
	void	*mlx_ptr;
	void	*mlx_window;
}	t_mlx_data;

typedef struct  s_img_data
{
	void	*img;
	char	*relative_path;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img_data;

#endif