/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 03:21:34 by albrusso          #+#    #+#             */
/*   Updated: 2023/05/16 01:07:03 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_width(char *path)
{
	int	width;
	int	fd;
	char	*buff;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		exit(0);
	width = 0;
	while (1)
	{
		buff = ft_calloc(2, 1);
		read(fd, buff, 1);
		if (buff[0] == '\n')
			break ;
		width++;
		free(buff);
	}
	free(buff);
	close(fd);
	return (width);
}

int	ft_height(char *path)
{
	int	height;
	int	fd;
	char	*buff;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		exit(0);
	height = 0;
	while (1)
	{
		buff = ft_calloc(2, 1);
		read(fd, buff, 1);
		if (buff[0] == '\n')
			height++;
		if (buff[0] == '\0')
		{
			height++;
			break ;
		}
		free(buff);
	}
	free(buff);
	close(fd);
	return(height);
}

char	**ft_alloc_maps(t_game *root)
{
	int	x;
	int	y;
	char	**map;

	x = root->width;
	y = root->height;
	map = malloc(sizeof(char *) * y);
	y--;
	while (y >= 0)
	{
		map[y] = malloc(sizeof(char) * x + 1);
		y--;
	}
	return(map);
}

void	ft_print_map(t_game *root)
{
	int	i;

	i = 0;
	while (i < root->height)
	{
		printf("1: %s", root->maps[i]);
		i++;
	}
}

void	ft_free_maps(int height, char **maps)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(maps[i]);
		i++;
	}
	free(maps);
	maps = NULL;
	
}