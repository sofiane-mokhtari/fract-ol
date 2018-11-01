/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_burn.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokhtar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 15:40:13 by smokhtar          #+#    #+#             */
/*   Updated: 2018/02/18 15:40:17 by smokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_burnning(void *param)
{
	t_ptr	*ptr;

	ptr = param;
	B.x1 = -2.1;
	B.x2 = 0.6;
	B.y1 = -1.2;
	B.y2 = 1.2;
	B.xs = 0;
	B.ys = 0;
	B.cr = 0.0;
	B.ci = 0.0;
	B.max = 50;
	B.zoom = 370;
	B.color = 0;
	B.b = 1;
	B.imgx = (B.x2 - B.x1) * B.zoom;
	B.imgy = (B.y2 - B.y1) * B.zoom;
	B.win = mlx_new_window(ptr->mlx, B.imgx, B.imgy, "burnning");
	ft_inter_burn(param);
}

void		ft_inter_burn(void *param)
{
	t_ptr	*ptr;

	ptr = param;
	B.p_img = mlx_new_image(ptr->mlx, ptr->win_t, ptr->win_t);
	B.i_img = ft_get_data_addr(B.p_img);
	B.x = B.xs;
	B.y = B.ys;
	ft_burn_cal(ptr, 0, 0, 0);
	mlx_clear_window(ptr->mlx, B.win);
	mlx_put_image_to_window(ptr->mlx, B.win, B.p_img, 0, 0);
	mlx_hook(B.win, ButtonPress, ButtonPressMask, ft_burn_click, param);
	mlx_key_hook(B.win, ft_key_burn, param);
	mlx_loop_hook(ptr->mlx, ft_burn_loop, param);
	mlx_loop(ptr->mlx);
}

void		ft_burn_cal(t_ptr *ptr, int i, float zi, float zr)
{
	while (B.x < B.imgx)
	{
		while (B.y < B.imgy)
		{
			B.cr = B.x / (float)B.zoom + B.x1;
			B.ci = B.y / (float)B.zoom + B.y1;
			while (((zr * zr + zi * zi) < 4) && i < B.max)
			{
				B.tmp = zr;
				zr = zr * zr - zi * zi + B.cr;
				zi = 2.0 * ft_abs(B.tmp * zi) + B.ci;
				i++;
			}
			if (i != B.max)
				B.i_img[B.x + B.y * ptr->win_t] = BC;
			i = 0;
			zr = 0;
			zi = 0;
			B.y++;
		}
		B.y = 0;
		B.x++;
	}
}

float		ft_abs(float x)
{
	return ((x > 0) ? x : x * -1.0);
}
