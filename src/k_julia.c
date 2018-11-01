/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_julia.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokhtar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 16:42:39 by smokhtar          #+#    #+#             */
/*   Updated: 2018/02/11 16:42:40 by smokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_key_ju(int k, void *param)
{
	t_ptr	*ptr;

	ptr = param;
	if (k == 53)
		exit(0);
	if (k == 49)
		JU.key = (JU.key == 0) ? 1 : 0;
	if (k == 15)
	{
		JU.x1 = -1;
		JU.x2 = 1;
		JU.y1 = -1.2;
		JU.y2 = 1.2;
		JU.zoom = 400.0;
	}
	if (k == 14)
		JU.bloque = (JU.bloque == 0) ? 1 : 0;
	return (1);
}

int		ft_ju_move(int x, int y, void *param)
{
	t_ptr	*ptr;

	ptr = param;
	if (JU.key == 1 && x > 0 && x < JU.imgx && y > 0 && y < JU.imgy)
	{
		JU.cr = 1 - x * 2 / JU.imgx;
		JU.ci = y * 1.5 / JU.imgy;
	}
	return (0);
}

int		ft_ju_loop(void *param)
{
	t_ptr	*ptr;

	ptr = param;
	if (JU.bloque)
	{
		JU.color += 1;
		if (JU.color == 50)
			JU.color = 0;
	}
	ft_inter_ju(param);
	return (0);
}

int		ft_ju_click(int b, int x, int y, void *param)
{
	t_ptr	*ptr;

	ptr = param;
	if (b == 1 || b == 5)
	{
		if (x > 400)
		{
			JU.x1 += 0.2;
			JU.y1 += (y > 480) ? 0.2 : 0;
			JU.y2 -= (y > 480) ? 0 : 0.5;
		}
		else
		{
			JU.x2 -= 0.1;
			JU.y1 += (y > 480) ? 0.2 : 0;
			JU.y2 -= (y > 480) ? 0 : 0.2;
		}
		JU.zoom += 100;
	}
	else if (b == 2 || b == 4)
		JU.zoom -= 50;
	return (0);
}
