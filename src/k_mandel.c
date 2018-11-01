/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_mandel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokhtar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 16:42:46 by smokhtar          #+#    #+#             */
/*   Updated: 2018/02/11 16:42:47 by smokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_key_man(int k, void *param)
{
	t_ptr	*ptr;

	ptr = param;
	if (k == 53)
		exit(0);
	if (k == 14)
		M.b = (M.b == 0) ? 1 : 0;
	if (k == 15)
	{
		M.x1 = -2.1;
		M.x2 = 0.6;
		M.y1 = -1.2;
		M.y2 = 1.2;
		M.zoom = 370.0;
	}
	return (1);
}

int		ft_man_click(int b, int x, int y, void *param)
{
	t_ptr	*ptr;

	ptr = param;
	if (b == 1 || b == 5)
	{
		if (x > 400)
		{
			M.x1 += 0.2;
			M.y1 += (y > 480) ? 0.2 : 0;
			M.y2 -= (y > 480) ? 0 : 0.2;
		}
		else
		{
			M.x2 -= 0.1;
			M.y1 += (y > 480) ? 0.2 : 0;
			M.y2 -= (y > 480) ? 0 : 0.2;
		}
		M.zoom += 100;
	}
	else if (b == 2 || b == 4)
		M.zoom -= 50;
	return (0);
}

int		ft_man_loop(void *param)
{
	t_ptr	*ptr;

	ptr = param;
	if (M.b == 0)
		M.color++;
	if (M.color == 50)
		M.color = 0;
	ft_inter_man(param);
	return (0);
}
