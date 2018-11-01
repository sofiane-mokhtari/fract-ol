/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokhtar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 16:24:38 by smokhtar          #+#    #+#             */
/*   Updated: 2018/02/11 16:24:39 by smokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int ac, char **av)
{
	t_ptr	ptr;
	void	*param;

	param = &ptr;
	ft_value(param);
	(ac == 1) ? ft_cr_menu(param, "menu") : 0;
	if (ac == 2)
	{
		(ft_strcmp("julia", av[1]) == 0) ? ft_julia(param) : 0;
		(ft_strcmp("mandelbrot", av[1]) == 0) ? ft_mandelbrot(param) : 0;
		(ft_strcmp("burning ship", av[1]) == 0) ? ft_burnning(param) : 0;
		(ft_strcmp("arbre", av[1]) == 0) ? ft_arbre(param) : 0;
	}
}

void	ft_value(void *param)
{
	t_ptr					*ptr;
	static pthread_mutex_t	mutex = PTHREAD_MUTEX_INITIALIZER;

	ptr = param;
	ptr->win_t = 1000;
	ptr->menu.chose = 0;
	ptr->mutex = mutex;
	if ((MENU.title = (char**)malloc(sizeof(char*) * 5)) == NULL)
		ft_error(2);
	MENU.title[0] = ft_strdup("ensemble de julia");
	MENU.title[1] = ft_strdup("ensemble de mandelbrot");
	MENU.title[2] = ft_strdup("burning ship");
	MENU.title[3] = ft_strdup("arbre");
	MENU.title[4] = 0;
	if (!(ptr->mlx = mlx_init()))
		ft_error(1);
}

void	ft_error(int cas)
{
	if (cas == 1)
		ft_putstr("error mlx_init");
	else if (cas == 2)
		ft_putstr("malloc error");
	exit(0);
}

int		*ft_get_data_addr(void *ptr)
{
	int		bpp;
	int		s_l;
	int		endian;

	return ((int*)mlx_get_data_addr(ptr, &(bpp), &(s_l), &(endian)));
}
