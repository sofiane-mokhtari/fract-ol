# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smokhtar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/11 16:27:55 by smokhtar          #+#    #+#              #
#    Updated: 2018/02/11 16:27:57 by smokhtar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

name = fractol

flag = -Wall -Werror -Wextra -O3

comp = -lmlx -framework OpenGL -framework AppKit

file =main\
	f_mandel\
	k_mandel\
	f_julia\
	k_julia\
	menu\
	f_burn\
	k_burn\
	seg\
	f_arbre\
	k_arbre\


Src = $(addprefix src/, $(file))

src = $(addsuffix .c, $(Src))

obj = $(addsuffix .o, $(file))

lib = -lft -Llibft -lmlx -Lminilibx_macos

X = -I/System/Library/Frameworks/Tk.framework/Versions/8.5/Headers/X11/

inc = -Iincludes -Ilibft/includes -Iminilibx -lpthread

object = $(addsuffix .o, $(Src))

all: $(name)

$(name) :
	make -C libft/
	make -C minilibx_macos/
	gcc -o $(name) $(lib) $(X) $(comp) $(SRC) $(src) $(inc)

e : 
	touch fractol
	rm fractol
	gcc -o $(name) $(flag) $(lib) $(X) $(comp) $(SRC) $(src) $(inc)
	./fractol

clean :
	make -C libft/ fclean
	make -C minilibx_macos/ clean
	rm -rf $(obj)

fclean : clean
	touch $(name)
	rm $(name)

re : fclean all