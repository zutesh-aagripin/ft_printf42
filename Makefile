# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aagripin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/11 13:17:52 by aagripin          #+#    #+#              #
#    Updated: 2019/10/15 19:53:50 by kbryce           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC = parse_functions.c precision.c width.c ft_switch.c ft_strupcase.c ft_itoa_base_u.c ft_strjoin.c ft_itoa_base.c big_function.c ft_putnbr_fd.c ft_strlen.c parse_format.c ft_printf.c ft_putstr_fd.c ft_putchar_fd.c functions.c ft_float.c ft_float_bigint.c ft_float_bigint_2.c ft_float_blah.c ft_float_precision.c ft_float_real_print.c ft_putchar.c ft_putstr.c ft_strcat.c ft_strchr.c ft_strnew.c

all: $(NAME)

$(NAME):
	@gcc -Wall -Wextra -Werror -c libftprintf.h $(SRC) 
	@ar rc $(NAME) $(SRC:.c=.o) libftprintf.h
%.o : %.c
	gcc -Wall -Wextra -Werror libftprintf.h -o $@ -c $<
clean:
	@/bin/rm -f $(SRC:.c=.o)
fclean: clean
	@/bin/rm -f $(NAME) libftprintf.h.gch
re: fclean all
.PHONY: all clean fclean re
