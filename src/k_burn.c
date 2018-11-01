/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_burn.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokhtar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 15:40:23 by smokhtar          #+#    #+#             */
/*   Updated: 2018/02/18 15:40:24 by smokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_key_burn(int k, void *param)
{
	t_ptr	*ptr;

	ptr = param;
	if (k == 53)
		exit(0);
	if (k == 49)
		B.b = (B.b == 0) ? 1 : 0;
	return (1);
}

int		ft_burn_click(int b, int x, int y, void *param)
{
	t_ptr	*ptr;

	ptr = param;
	if (b == 1 || b == 5)
	{
		if (x > 400)
		{
			B.x1 += 0.2;
			B.y1 += (y > 480) ? 0.2 : 0;
			B.y2 -= (y > 480) ? 0 : 0.2;
		}
		else
		{
			B.x2 -= 0.1;
			B.y1 += (y > 480) ? 0.2 : 0;
			B.y2 -= (y > 480) ? 0 : 0.2;
		}
		B.zoom += 100;
	}
	else if (b == 2 || b == 4)
		B.zoom -= 50;
	return (0);
}

int		ft_burn_loop(void *param)
{
	t_ptr	*ptr;

	ptr = param;
	if (B.b == 0)
		B.color++;
	if (B.color == 50)
		B.color = 0;
	ft_inter_burn(param);
	return (0);
}
