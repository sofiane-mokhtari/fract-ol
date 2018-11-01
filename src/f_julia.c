/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_julia.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokhtar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 16:42:53 by smokhtar          #+#    #+#             */
/*   Updated: 2018/02/11 16:42:56 by smokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_julia(void *param)
{
	t_ptr	*ptr;

	ptr = param;
	JU.x1 = -1;
	JU.x2 = 1;
	JU.y1 = -1.2;
	JU.y2 = 1.2;
	JU.xs = 0;
	JU.ys = 0;
	JU.cr = 0.0;
	JU.ci = 0.0;
	JU.zr = 0;
	JU.zi = 0;
	JU.i = 0;
	JU.max = 50;
	JU.key = 1;
	JU.bloque = 0;
	JU.cr = 0.285;
	JU.ci = 0.01;
	JU.color = 0;
	JU.zoom = 400.0;
	JU.imgx = (JU.x2 - JU.x1) * JU.zoom;
	JU.imgy = (JU.y2 - JU.y1) * JU.zoom;
	JU.win = mlx_new_window(ptr->mlx, JU.imgx, JU.imgy, "julia");
	ft_inter_ju(param);
}

void		ft_inter_ju(void *param)
{
	t_ptr	*ptr;

	ptr = param;
	JU.p_img = mlx_new_image(ptr->mlx, ptr->win_t, ptr->win_t);
	JU.i_img = ft_get_data_addr(JU.p_img);
	JU.x = JU.xs;
	JU.y = JU.ys;
	pthread_create(&ptr->thread, NULL, ft_ju_cal, (void*)ptr);
	pthread_join(ptr->thread, NULL);
	mlx_clear_window(ptr->mlx, JU.win);
	mlx_put_image_to_window(ptr->mlx, JU.win, JU.p_img, 0, 0);
	mlx_key_hook(JU.win, ft_key_ju, param);
	mlx_hook(JU.win, MotionNotify, PointerMotionMask, ft_ju_move, param);
	mlx_hook(JU.win, ButtonPress, ButtonPressMask, ft_ju_click, param);
	mlx_loop_hook(ptr->mlx, ft_ju_loop, param);
	mlx_loop(ptr->mlx);
}

void		*ft_ju_cal(void *p)
{
	t_ptr	*ptr;

	ptr = p;
	while (JU.x < JU.imgx)
	{
		while (JU.y < JU.imgy)
		{
			JU.zr = JU.x / JU.zoom + JU.x1;
			JU.zi = JU.y / JU.zoom + JU.y1;
			while (((JU.zr * JU.zr + JU.zi * JU.zi) < 4) && JU.i < JU.max)
				ptr->ju = ft_algo(ptr->ju);
			if (JU.i != JU.max)
			{
				pthread_mutex_lock(&ptr->mutex);
				JU.i_img[JU.x + JU.y * ptr->win_t] = CO;
				pthread_mutex_unlock(&ptr->mutex);
			}
			JU.i = 0;
			JU.y++;
		}
		JU.y = JU.ys;
		JU.x++;
	}
	pthread_exit(NULL);
}

t_ju		ft_algo(t_ju ju)
{
	ju.tmp = ju.zr;
	ju.zr = ju.zr * ju.zr - ju.zi * ju.zi + ju.cr;
	ju.zi = 2.0 * ju.tmp * ju.zi + ju.ci;
	ju.i++;
	return (ju);
}
