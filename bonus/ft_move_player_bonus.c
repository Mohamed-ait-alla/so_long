/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-all <mait-all@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:27:16 by mait-all          #+#    #+#             */
/*   Updated: 2025/01/26 10:25:21 by mait-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"


void	ft_player_dying_animation(t_mlx_data *mlx)
{
    static int frame = 0;
    static int delay = 0;

	if (mlx->is_died == 0)
	{
    	if (delay++ % 15000 == 0)    
    	{
        	if (frame < 10)
        	{
            	mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window, mlx->player_dying[frame], mlx->player_pos_x * SIZE, mlx->player_pos_y * SIZE);
            	frame++;            
        	}
        	else
				ft_lose();
    	}
	}
}

void ft_chase_player(t_mlx_data *mlx)
{
    int diff_x;
    int diff_y;
    int i;

    i = 0;
    while (i < mlx->n_of_ghosts)
    {
        if (mlx->wanted_ghost == i)
        {
            diff_x = mlx->player_pos_x - mlx->ghosts[i].old_pos_x;
            diff_y = mlx->player_pos_y - mlx->ghosts[i].old_pos_y;
            if (abs(diff_x) > abs(diff_y))
            {
                if (diff_x > 0 && mlx->map[mlx->ghosts[i].old_pos_y][mlx->ghosts[i].old_pos_x + 1] != '1')
                    mlx->ghosts[i].n_pos_x++;
                else if (diff_x < 0 && mlx->map[mlx->ghosts[i].old_pos_y][mlx->ghosts[i].old_pos_x - 1] != '1')
                    mlx->ghosts[i].n_pos_x--;
            }
            else
            {
                if (diff_y > 0 && mlx->map[mlx->ghosts[i].old_pos_y + 1][mlx->ghosts[i].old_pos_x] != '1')
                    mlx->ghosts[i].n_pos_y++;
                else if (diff_y < 0 && mlx->map[mlx->ghosts[i].old_pos_y - 1][mlx->ghosts[i].old_pos_x] != '1')
                    mlx->ghosts[i].n_pos_y--;
            }
            if (mlx->map[mlx->ghosts[i].old_pos_y][mlx->ghosts[i].old_pos_x] == 'C')
                mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window, mlx->sprites.food, mlx->ghosts[i].old_pos_x * SIZE, mlx->ghosts[i].old_pos_y * SIZE);
            else
                mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window, mlx->sprites.black_wall, mlx->ghosts[i].old_pos_x * SIZE, mlx->ghosts[i].old_pos_y * SIZE);
            mlx->ghosts[i].old_pos_x = mlx->ghosts[i].n_pos_x;
            mlx->ghosts[i].old_pos_y = mlx->ghosts[i].n_pos_y;
            if (mlx->ghosts[i].c_index > 6)
                mlx->ghosts[i].c_index--;
            mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window, mlx->sprites.ghost_left[mlx->ghosts[i].c_index], mlx->ghosts[i].n_pos_x * SIZE, mlx->ghosts[i].n_pos_y * SIZE);
        }
        i++;
    }
}
void	ft_ghost_anim(t_mlx_data *mlx)
{
	static int i = 0;
	int j = 0;
	int x = 0;
	i++;

	if (!mlx->is_died)
		return ;
	if (!ft_check_distance_with_ghosts(mlx, mlx->player_pos_x, mlx->player_pos_y))
	{
		if (i == 1000)
			ft_chase_player(mlx);
	}
	while (j < mlx->n_of_ghosts)
	{
		if (i == 59999)
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window, mlx->sprites.ghost_right[x], mlx->ghosts[j].old_pos_x * SIZE, mlx->ghosts[j].old_pos_y * SIZE);
		else if (i == 69990)
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window, mlx->sprites.ghost_down[x], mlx->ghosts[j].old_pos_x * SIZE, mlx->ghosts[j].old_pos_y  * SIZE);
		else if (i == 89999)
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window, mlx->sprites.ghost_left[x], mlx->ghosts[j].old_pos_x * SIZE, mlx->ghosts[j].old_pos_y  * SIZE);
		j++;
		x++;
		if (x > 5)
			x = 0;
	}
	if (i == 89999)
		i = 0;
}

int	ft_animation(t_mlx_data *mlx)
{
	static int	frame_counter = 0;
	frame_counter++;
	ft_ghost_anim(mlx);
	ft_player_dying_animation(mlx);
	if (!mlx->is_died)
		return (0);
	if (frame_counter == 25999)
	{
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window, mlx->player_actions[mlx->direction][0], mlx->player_pos_x * SIZE, mlx->player_pos_y * SIZE);
	}
	else if (frame_counter == 35990)
	{
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window, mlx->player_actions[mlx->direction][1], mlx->player_pos_x * SIZE, mlx->player_pos_y * SIZE);
	}
	else if (frame_counter == 49999)
	{
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window, mlx->player_actions[mlx->direction][2], mlx->player_pos_x * SIZE, mlx->player_pos_y * SIZE);
		frame_counter = 0;
	}
	return (0);
}

static void	ft_move_to_direction(t_mlx_data *mlx, int new_pos_x, int new_pos_y)
{
	if (mlx->map[new_pos_y][new_pos_x] == 'C')
	{
		mlx->map[new_pos_y][new_pos_x] = '0';
		mlx->n_check++;

	}
	if (mlx->map[new_pos_y][new_pos_x] != '1')
	{
		if (mlx->map[new_pos_y][new_pos_x] == 'E' && mlx->n_of_collectibles == mlx->n_check)
			ft_win();
		else if (mlx->map[new_pos_y][new_pos_x] != 'E' || mlx->n_of_collectibles == mlx->n_check)
		{
			mlx->n_of_moves++;
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window, mlx->sprites.black_wall, mlx->player_pos_x * SIZE, mlx->player_pos_y * SIZE);
			mlx->player_pos_x = new_pos_x;
			mlx->player_pos_y = new_pos_y;
		}
	}
}

int	ft_move_player(int keycode, t_mlx_data *mlx)
{
	int	new_pos_x;
	int	new_pos_y;

	new_pos_x = mlx->player_pos_x;
	new_pos_y = mlx->player_pos_y;
	if (!mlx->is_died)
		return (0);
	if (keycode == XK_Escape)
		close_window_with_x(mlx);
	if (keycode == XK_w || keycode == XK_Up)
	{
		new_pos_y--;
		mlx->direction = 1;
		ft_move_to_direction(mlx, new_pos_x, new_pos_y);
	}
	else if (keycode == XK_d || keycode == XK_Right)
	{
		new_pos_x++;
		mlx->direction = 0;
		ft_move_to_direction(mlx, new_pos_x, new_pos_y);
	}
	else if (keycode == XK_s || keycode == XK_Down)
	{
		new_pos_y++;
		mlx->direction = 3;
		ft_move_to_direction(mlx, new_pos_x, new_pos_y);
	}
	else if (keycode == XK_a || keycode == XK_Left)
	{
		new_pos_x--;
		mlx->direction = 2;
		ft_move_to_direction(mlx, new_pos_x, new_pos_y);
	}
	return (0);
}