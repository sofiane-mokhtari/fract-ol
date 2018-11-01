/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokhtar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 16:24:44 by smokhtar          #+#    #+#             */
/*   Updated: 2018/02/11 16:24:45 by smokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <stdio.h>
# include <X.h>
# include <pthread.h>

# define BL 0x0000FE
# define BC 0xFFF0FF
# define O 0xFF6600

# define M ptr->man
# define JU ptr->ju
# define MENU ptr->menu
# define B ptr->burn
# define AB ptr->ab

# define SEG 0.2
# define RAD M_PI/180
# define T 200/i

# define CO 000000000 + JU.i * 255000000 / JU.max + JU.color * 255000000 / 50
# define MO 55055055 + i * 200200200/ M.max + M.color * 255000000 / 50

typedef struct		s_menu
{
	void	*win;
	char	**title;
	int		chose;
	int		menu_len;
}					t_menu;

typedef struct		s_mandel
{
	void	*win;
	void	*p_img;
	int		*i_img;
	float	x1;
	float	x2;
	float	y1;
	float	y2;
	int		zoom;
	float	zoomx;
	float	zoomy;
	int		max;
	float	imgx;
	float	imgy;
	float	cr;
	float	ci;
	float	tmp;
	int		x;
	int		y;
	int		ys;
	int		xs;
	int		color;
	int		b;
}					t_mandel;

typedef struct		s_burn
{
	void	*win;
	void	*p_img;
	int		*i_img;
	float	x1;
	float	x2;
	float	y1;
	float	y2;
	int		zoom;
	float	zoomx;
	float	zoomy;
	int		max;
	float	imgx;
	float	imgy;
	float	cr;
	float	ci;
	float	tmp;
	int		x;
	int		y;
	int		ys;
	int		xs;
	int		color;
	int		b;
}					t_burn;

typedef struct		s_ju
{
	void	*win;
	void	*p_img;
	int		*i_img;
	float	x1;
	float	x2;
	float	y1;
	float	y2;
	float	zoom;
	int		max;
	float	imgx;
	float	imgy;
	float	cr;
	float	ci;
	float	zr;
	float	zi;
	float	tmp;
	int		i;
	int		x;
	int		xs;
	int		y;
	int		ys;
	int		color;
	int		key;
	int		bloque;
}					t_ju;

typedef struct		s_arbre
{
	void		*win;
	float		a1;
	float		a2;
	int			i;
}					t_arbre;

typedef struct		s_droite
{
	float		xa;
	float		ya;
	float		xb;
	float		yb;
	float		coef;
	float		b;
	int			color;
}					t_dr;

typedef struct		s_cood
{
	int			x;
	int			y;
}					t_cood;

typedef struct		s_ptr
{
	void			*mlx;
	t_menu			menu;
	t_mandel		man;
	t_ju			ju;
	t_burn			burn;
	t_arbre			ab;
	unsigned int	win_t;
	pthread_t		thread;
	pthread_mutex_t	mutex;
}					t_ptr;

void				ft_put_seg(t_ptr *ptr, t_dr dr, int color);
t_dr				ft_crs(int xa, int ya, int xb, int yb);
int					ft_draw_seg(t_ptr *ptr, t_dr dr);
t_cood				ft_fill(float x, float y);

int					ft_arbre(void *param);
int					ft_print_next(void *param, int x_s, int y_s);
int					ft_double(void *prm, t_cood xy, int i);
int					ft_stick(void *prm, t_cood xy, int t, int i);
int					ft_key_arbre(int k, void *param);

float				ft_abs(float x);
int					ft_arbre_move(int x, int y, void *param);

int					ft_cr_menu(void *param, char *title);
void				ft_print_menu(void *param);
int					ft_key_m(int k, void *param);
int					ft_tablen(char **tab);

void				ft_error(int cas);
int					*ft_get_data_addr(void *ptr);
void				ft_value1(void *param);

void				ft_inter_man(void *param);
void				ft_man_cal(t_ptr *ptr, int i, float zr, float zi);
void				ft_mandelbrot(void *param);
int					ft_key_man(int k, void *param);
int					ft_man_click(int b, int x, int y, void *param);
int					ft_man_loop(void *param);

void				ft_inter_burn(void *param);
void				ft_burn_cal(t_ptr *ptr, int i, float zi, float zr);
void				ft_burnning(void *param);
int					ft_key_burn(int k, void *param);
int					ft_burn_click(int b, int x, int y, void *param);
int					ft_burn_loop(void *param);

void				ft_inter_ju(void *param);
void				*ft_ju_cal(void *ptr);
void				ft_julia(void *param);
void				ft_value(void *param);
t_ju				ft_algo(t_ju ju);

int					ft_key_ju(int k, void *param);
int					ft_ju_move(int x, int y, void *param);
int					ft_ju_loop(void *param);
int					ft_ju_click(int b, int x, int y, void *param);
#endif
