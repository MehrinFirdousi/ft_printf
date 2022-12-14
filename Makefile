# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfirdous <mfirdous@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/12 11:10:32 by mfirdous          #+#    #+#              #
#    Updated: 2022/07/18 11:48:18 by mfirdous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	srcs/ft_printf.c srcs/ft_printf_utils.c

OBJS		= ${SRCS:.c=.o}

HEADERS		= include

NAME		= libftprintf.a

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${HEADERS}

${NAME}:	${OBJS}
			${MAKE} -C libft
			@cp libft/libft.a .
			@mv libft.a ${NAME}
			ar crs ${NAME} ${OBJS}

all:		${NAME}
		
clean:
			rm -f ${OBJS}
			rm -f ${BOBJS}
			${MAKE} -C libft clean

fclean:		clean
			rm -f ${NAME}
			${MAKE} -C libft fclean

re:			fclean all
