# *************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smokhtar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 18:26:26 by smokhtar          #+#    #+#              #
#    Updated: 2018/02/13 14:44:42 by smokhtar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

SRC_NAME =ft_charislower.c\
		ft_conv_base.c\
		ft_charisupper.c\
		ft_putfile.c\
		ft_puttable_int.c\
		ft_strjoinfree.c\
		ft_puttable.c\
		ft_lstmap.c\
		ft_lstadd.c\
		ft_lstiter.c\
		ft_lstdel.c\
		ft_lstdelone.c\
		ft_lstnew.c\
		ft_strsplit.c\
		ft_memmove.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_memccpy.c\
		ft_memcpy.c\
		ft_strnstr.c\
		ft_strstr.c\
		ft_strmapi.c\
		ft_strlcat.c\
		ft_strncat.c\
		ft_strcat.c\
		ft_putendl.c\
		ft_strrchr.c\
		ft_strtrim.c\
		ft_putchar_fd.c\
	   	ft_putstr_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
		ft_tolower.c\
		ft_toupper.c\
		ft_isprint.c\
		ft_isascii.c\
		ft_isalnum.c\
		ft_isdigit.c\
		ft_isalpha.c\
		ft_itoa.c\
		ft_putnbr.c\
		ft_atoi.c\
		ft_bzero.c\
		ft_putchar.c\
		ft_strcmp.c\
		ft_strequ.c\
		ft_strlen.c\
		ft_strnequ.c\
		ft_memalloc.c\
		ft_putstr.c\
		ft_strcpy.c\
		ft_striter.c\
		ft_strmap.c\
		ft_strnew.c\
		ft_memdel.c\
		ft_strchr.c\
		ft_strdel.c\
		ft_striteri.c\
		ft_strncmp.c\
		ft_strsub.c\
		ft_memset.c\
		ft_strclr.c\
		ft_strdup.c\
		ft_strjoin.c\
		ft_strncpy.c\
		get_next_line.c\

object = ft_puttable_int.o get_next_line.o ft_lstiter.o ft_conv_base.o ft_putfile.o ft_charisupper.o ft_charislower.o ft_strjoinfree.o ft_puttable.o ft_lstmap.o ft_strnstr.o ft_lstadd.o ft_lstdel.o ft_lstdelone.o ft_lstnew.o ft_strsplit.o ft_memmove.o ft_memchr.o ft_memcmp.o ft_memccpy.o ft_memcpy.o ft_isalpha.o ft_strstr.o ft_strmapi.o ft_strlcat.o ft_strncat.o ft_strcat.o ft_putendl.o ft_strrchr.o ft_isprint.o ft_strtrim.o ft_isascii.o ft_tolower.o ft_toupper.o ft_putchar_fd.o ft_putendl_fd.o ft_putstr_fd.o ft_putendl_fd.o ft_putnbr_fd.o ft_isalnum.o ft_isdigit.o ft_itoa.o ft_putnbr.o ft_atoi.o ft_bzero.o ft_putchar.o ft_strcmp.o ft_strequ.o ft_strlen.o ft_strnequ.o ft_memalloc.o ft_putstr.o ft_strcpy.o ft_striter.o ft_strmap.o ft_strnew.o ft_memdel.o ft_strchr.o ft_strdel.o ft_striteri.o ft_strncmp.o ft_strsub.o ft_memset.o ft_strclr.o ft_strdup.o ft_strjoin.o ft_strncpy.o

head = includes

src = $(addprefix src/, $(SRC_NAME))

flag = -Wall -Werror -Wextra 

all: $(NAME) 

$(NAME):
	gcc -c $(flag) $(src) -I$(head)
	ar rcs libft.a $(object)

clean:
	rm -f $(object)

fclean: clean
	rm -f libft.a

re : fclean all
