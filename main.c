/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 02:50:19 by albrusso          #+#    #+#             */
/*   Updated: 2023/05/16 01:11:29 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(t_game *root)
{
	if (root->img.background)
		mlx_destroy_image(root->mlx_ptr, root->img.background);
	if (root->img.collect)
		mlx_destroy_image(root->mlx_ptr, root->img.collect);
	if (root->img.exit)
		mlx_destroy_image(root->mlx_ptr, root->img.exit);
	if (root->img.minotaur)
		mlx_destroy_image(root->mlx_ptr, root->img.minotaur);
	if (root->img.wall)
		mlx_destroy_image(root->mlx_ptr, root->img.wall);
	if (root->mlx_win)
		mlx_destroy_window(root->mlx_ptr, root->mlx_win);
	if (root->mlx_ptr)
	{
		mlx_destroy_display(root->mlx_ptr);
		free(root->mlx_ptr);
	}
	if (root->maps)
		ft_free_maps(root->height, root->maps);
	//printf("Errore\n");
	exit(0);
}

char	**ft_read_map(char *path, t_game *root)
{
	int	fd;
	char	*buffer;
	int	x;
	int	y;

	y = 0;
	x = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		exit (0);
	while (1)
	{
		buffer = ft_calloc(2, 1);
		read(fd, buffer, 1);
		if (buffer[0] == '\0')
		{
			root->maps[y][x] = '\0';
			break ;
		}
		else
		{
			if (buffer[0] == '\n')
			{
				root->maps[y][x] = '\0';
				x = 0;
				y++;
			}
			else
			{
				root->maps[y][x] = buffer[0];
				x++;
			}
		}
		free(buffer);
	}
	free(buffer);
	return(root->maps);
}

void	ft_init_maps(t_game *root, char *path)
{
	root->width = ft_width(path);
	root->height = ft_height(path);
	root->maps = ft_alloc_maps(root);
}

void	ft_minotaur_position(t_game *root)
{
	int	x;
	int	y;

	y = 0;
	while (y < root->height)
	{
		x = 0;
		while (x < root->width)
		{
			if (root->maps[y][x] == 'P')
			{
				root->minotaur_x = x;
				root->minotaur_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	ft_init(t_game *root, char *path)
{
	ft_init_maps(root, path);
	ft_read_map(path, root);
	ft_minotaur_position(root);
	//ft_print_map(root);
}

int	main(int ac, char *av[])
{
	t_game	root;

	if (ac != 2)
		return (0);
	else
	{
		root.maps = NULL;
		ft_init(&root, av[1]);
		ft_check(&root);
		ft_start_game(&root);
	}
}