/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_arbre.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokhtar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 16:33:29 by smokhtar          #+#    #+#             */
/*   Updated: 2018/02/18 16:33:31 by smokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_stick(void *prm, t_cood xy, int t, int i)
{
	t_ptr	*ptr;
	float	x;
	float	y;

	ptr = prm;
	if (t == 0)
	{
		x = xy.x - cos(AB.a1 * 5 * i * RAD) * T;
		y = xy.y + sin(AB.a1 * 5 * i * RAD) * T;
		ft_put_seg(prm, ft_crs(xy.x, xy.y, x, y), BC);
		xy = ft_fill(x, y);
		return (ft_double(prm, xy, i));
	}
	else
	{
		x = xy.x - cos(AB.a2 * 5 * i * RAD) * T;
		y = xy.y - sin(AB.a2 * 5 * i * RAD) * T;
		ft_put_seg(prm, ft_crs(xy.x, xy.y, x, y), O);
		xy = ft_fill(x, y);
		return (ft_double(prm, xy, i));
	}
}

int		ft_double(void *prm, t_cood xy, int i)
{
	t_ptr *ptr;

	ptr = prm;
	i++;
	if (i == AB.i)
		return (0);
	ft_stick(prm, xy, 0, i);
	ft_stick(prm, xy, 1, i);
	return (0);
}

int		ft_print_next(void *param, int x_s, int y_s)
{
	t_cood	xy;
	int		i;
	t_ptr	*ptr;

	ptr = param;
	i = 0;
	xy.x = x_s - 200;
	xy.y = y_s;
	ft_put_seg(param, ft_crs(x_s, y_s, xy.x, xy.y), BC);
	ft_double(param, xy, i);
	return (0);
}

int		ft_arbre(void *param)
{
	t_ptr	*ptr;

	ptr = param;
	AB.i = 1;
	AB.a1 = 0;
	AB.a2 = 0;
	AB.win = mlx_new_window(ptr->mlx, ptr->win_t, ptr->win_t, "fractol arbre");
	ft_print_next(param, 900, 500);
	mlx_key_hook(AB.win, ft_key_arbre, param);
	mlx_hook(AB.win, MotionNotify, PointerMotionMask, ft_arbre_move, param);
	mlx_loop(ptr->mlx);
	return (0);
}
