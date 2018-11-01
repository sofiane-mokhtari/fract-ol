/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokhtar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 19:34:01 by smokhtar          #+#    #+#             */
/*   Updated: 2018/02/05 19:34:02 by smokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_key_m(int k, void *param)
{
	t_ptr	*ptr;

	ptr = param;
	(k == 53) ? exit(0) : 0;
	if (k == 125 || k == 126)
	{
		MENU.chose += (k == 125) ? 1 : -1;
		if (MENU.chose == MENU.menu_len)
			MENU.chose = 0;
		if (MENU.chose == -1)
			MENU.chose = MENU.menu_len - 1;
		ft_print_menu(param);
	}
	else if (k == 36)
	{
		if (MENU.chose == 0)
			ft_julia(param);
		else if (MENU.chose == 1)
			ft_mandelbrot(param);
		else if (MENU.chose == 2)
			ft_burnning(param);
		else if (MENU.chose == 3)
			ft_arbre(param);
	}
	return (1);
}

void	ft_print_menu(void *param)
{
	t_ptr	*ptr;
	int		i;
	int		x;
	int		color;

	i = 0;
	ptr = param;
	mlx_clear_window(ptr->mlx, MENU.win);
	while (MENU.title[i])
	{
		x = 10 + ((MENU.chose == i) ? 10 : 0);
		color = (MENU.chose == i) ? O : BL;
		mlx_string_put(ptr->mlx, MENU.win, x, 50 * i, color, MENU.title[i]);
		i++;
	}
}

int		ft_cr_menu(void *param, char *title)
{
	t_ptr	*ptr;

	ptr = param;
	MENU.chose = 0;
	MENU.menu_len = ft_tablen(MENU.title);
	MENU.win = mlx_new_window(ptr->mlx, 500, MENU.menu_len * 50, title);
	ft_print_menu(param);
	mlx_key_hook(MENU.win, ft_key_m, param);
	mlx_loop(ptr->mlx);
	return (MENU.chose);
}

int		ft_tablen(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}
