/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 00:22:24 by albrusso          #+#    #+#             */
/*   Updated: 2023/05/16 01:25:55 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, void *r)
{
	t_game	*root;

	root = (t_game *)r;
	if (keycode == 65307)
		ft_close(root);
	printf("%d\n", keycode);
}