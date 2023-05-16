/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 08:34:25 by albrusso          #+#    #+#             */
/*   Updated: 2023/05/16 01:21:51 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_img(t_game *root)
{
	root->img.exit = mlx_xpm_file_to_image(root->mlx_ptr, "image/exit.xpm", &root->img.width, &root->img.height);
	root->img.minotaur = mlx_xpm_file_to_image(root->mlx_ptr, "image/minotaur.xpm", &root->img.width, &root->img.height);
	root->img.wall = mlx_xpm_file_to_image(root->mlx_ptr, "image/wall.xpm", &root->img.width, &root->img.height);
	root->img.background = mlx_xpm_file_to_image(root->mlx_ptr, "image/background.xpm", &root->img.width, &root->img.height);
	root->img.collect = mlx_xpm_file_to_image(root->mlx_ptr, "image/collect.xpm", &root->img.width, &root->img.height);
}

void	ft_choose_img(t_game *root, int x, int y)
{
	if (root->maps[y][x] == '1')
		mlx_put_image_to_window(root->mlx_ptr, root->mlx_win, root->img.wall, x * 64, y * 64);
	else if (root->maps[y][x] == '0')
		mlx_put_image_to_window(root->mlx_ptr, root->mlx_win, root->img.background, x * 64, y * 64);
	else if (root->maps[y][x] == 'P')
		mlx_put_image_to_window(root->mlx_ptr, root->mlx_win, root->img.minotaur, x * 64, y * 64);
	else if (root->maps[y][x] == 'C')
		mlx_put_image_to_window(root->mlx_ptr, root->mlx_win, root->img.collect, x * 64, y * 64);
	else if (root->maps[y][x] == 'E')
		mlx_put_image_to_window(root->mlx_ptr, root->mlx_win, root->img.exit, x * 64, y * 64);
}

void	ft_put_img(t_game *root)
{
	int	x;
	int	y;

	y = 0;
	while (y < root->height)
	{
		x = 0;
		while (x < root->width)
		{
			ft_choose_img(root, x , y);
			x++;
		}
		y++;
	}
}

void	ft_start_game(t_game *root)
{
	root->mlx_ptr = mlx_init();
	root->mlx_win = mlx_new_window(root->mlx_ptr, 64 * root->width, 64 * root->height, "so_long");
	ft_init_img(root);
	ft_put_img(root);
	mlx_hook(root->mlx_win, 17, 0, ft_close, root);
	mlx_key_hook(root->mlx_win, key_hook, &root);
	mlx_loop(root->mlx_ptr);
}