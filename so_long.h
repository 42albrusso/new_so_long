/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 02:50:24 by albrusso          #+#    #+#             */
/*   Updated: 2023/05/16 01:29:17 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx_linux/mlx.h"
#include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_sprite
{
	void	*minotaur;
	void	*exit;
	void	*collect;
	void	*wall;
	void	*background;
	int	width;
	int	height;
	int	line_size;
	int	endian;
}			t_sprite;


typedef struct s_game
{
    void    *mlx_ptr;
    void    *mlx_win;
    int	max_collect;
    int	collected;
    int	minotaur_x;
    int	minotaur_y;
    int	width;
    int	height;
    t_sprite	img;
    char	**maps;
}               t_game;

int	ft_width(char *path);
int	ft_height(char *path);
char	**ft_alloc_maps(t_game *root);
void	ft_print_map(t_game *root);
int	ft_close(t_game *root);
void	ft_check(t_game *root);
void	ft_free_maps(int height, char **maps);
void	ft_start_game(t_game *root);
int	key_hook(int keycode, void *r);