/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_mandel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokhtar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 16:43:01 by smokhtar          #+#    #+#             */
/*   Updated: 2018/02/11 16:43:03 by smokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_mandelbrot(void *param)
{
	t_ptr	*ptr;

	ptr = param;
	M.x1 = -2.1;
	M.x2 = 0.6;
	M.y1 = -1.2;
	M.y2 = 1.2;
	M.xs = 0;
	M.ys = 0;
	M.cr = 0.0;
	M.ci = 0.0;
	M.max = 50;
	M.zoom = 370;
	M.color = 0;
	M.b = 0;
	M.imgx = (M.x2 - M.x1) * M.zoom;
	M.imgy = (M.y2 - M.y1) * M.zoom;
	M.win = mlx_new_window(ptr->mlx, M.imgx, M.imgy, "fractol");
	ft_inter_man(param);
}

void		ft_inter_man(void *param)
{
	t_ptr	*ptr;

	ptr = param;
	M.p_img = mlx_new_image(ptr->mlx, ptr->win_t, ptr->win_t);
	M.i_img = ft_get_data_addr(M.p_img);
	M.x = M.xs;
	M.y = M.ys;
	ft_man_cal(ptr, 0, 0, 0);
	mlx_clear_window(ptr->mlx, M.win);
	mlx_put_image_to_window(ptr->mlx, M.win, M.p_img, 0, 0);
	mlx_hook(M.win, ButtonPress, ButtonPressMask, ft_man_click, param);
	mlx_key_hook(M.win, ft_key_man, param);
	mlx_loop_hook(ptr->mlx, ft_man_loop, param);
	mlx_loop(ptr->mlx);
}

void		ft_man_cal(t_ptr *ptr, int i, float zr, float zi)
{
	while (M.x < M.imgx)
	{
		while (M.y < M.imgy)
		{
			M.cr = M.x / (float)M.zoom + M.x1;
			M.ci = M.y / (float)M.zoom + M.y1;
			while (((zr * zr + zi * zi) < 4) && i < M.max)
			{
				M.tmp = zr;
				zr = zr * zr - zi * zi + M.cr;
				zi = 2.0 * M.tmp * zi + M.ci;
				i++;
			}
			if (i != M.max)
				M.i_img[M.x + M.y * ptr->win_t] = MO;
			i = 0;
			zr = 0;
			zi = 0;
			M.y++;
		}
		M.y = 0;
		M.x++;
	}
}
