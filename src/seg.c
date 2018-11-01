/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokhtar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 16:53:45 by smokhtar          #+#    #+#             */
/*   Updated: 2018/02/18 16:53:47 by smokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			ft_draw_seg(t_ptr *ptr, t_dr dr)
{
	float	x;
	float	y;
	float	c;

	x = dr.xa;
	y = dr.ya;
	if (dr.xa == dr.xb)
	{
		while (y < dr.yb)
		{
			y = y + SEG;
			mlx_pixel_put(ptr->mlx, AB.win, y, x, dr.color);
		}
		return (0);
	}
	c = dr.coef;
	while (((y <= dr.yb && c >= 0) || (y >= dr.yb && c < 0)) && x <= dr.xb)
	{
		y = x * dr.coef + dr.b;
		mlx_pixel_put(ptr->mlx, AB.win, y, x, dr.color);
		x = x + SEG;
	}
	return (0);
}

void		ft_put_seg(t_ptr *ptr, t_dr dr, int color)
{
	dr.color = color;
	ft_draw_seg(ptr, dr);
}

t_dr		ft_crs(int xa, int ya, int xb, int yb)
{
	t_dr dr;

	dr.coef = (double)(yb - ya) / (xb - xa);
	dr.b = (double)yb - (dr.coef * xb);
	if (xa > xb && ya > yb)
		return (ft_crs(xb, yb, xa, ya));
	else if (xa > xb && dr.coef < 0)
		return (ft_crs(xb, yb, xa, ya));
	else if (xa > xb && ya == yb)
		return (ft_crs(xb, ya, xa, yb));
	else if (ya > yb && xa == xb)
		return (ft_crs(xa, yb, xb, ya));
	else
	{
		dr.xa = xa;
		dr.xb = xb;
		dr.ya = ya;
		dr.yb = yb;
	}
	return (dr);
}
