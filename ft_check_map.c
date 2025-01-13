/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-all <mait-all@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:30:19 by mait-all          #+#    #+#             */
/*   Updated: 2025/01/13 16:03:55 by mait-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_calc_width_and_height(char	*file, t_frame *frame)
{
	int	fd;
	int	count;

	count = 0;
	fd = open(file, O_RDONLY);
	if (fd <= 0)
		printf("file descriptor not valid");
	frame->n_col = ft_strlen(get_next_line(fd)) - 1;
	while (get_next_line(fd))
		count++;
	frame->n_row = count + 1;
}