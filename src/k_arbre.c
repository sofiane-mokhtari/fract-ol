/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_arbre.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokhtar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 16:33:34 by smokhtar          #+#    #+#             */
/*   Updated: 2018/02/18 16:33:36 by smokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			ft_key_arbre(int k, void *param)
{
	t_ptr	*ptr;

	ptr = param;
	if (k == 53)
		exit(0);
	if (k == 49)
		AB.i++;
	if (k == 36 && AB.i != 0)
		AB.i--;
	mlx_clear_window(ptr->mlx, AB.win);
	ft_print_next(param, 900, 500);
	return (0);
}

int			ft_arbre_move(int x, int y, void *param)
{
	t_ptr	*ptr;

	ptr = param;
	mlx_clear_window(ptr->mlx, AB.win);
	if (x > 0 && x < 1000 && y > 0 && y < 1000)
	{
		AB.a1 = x * 180 / ptr->win_t;
		AB.a2 = y * 180 / ptr->win_t;
	}
	ft_print_next(param, 900, 500);
	return (0);
}

t_cood		ft_fill(float x, float y)
{
	t_cood	stru;

	stru.x = x;
	stru.y = y;
	return (stru);
}
