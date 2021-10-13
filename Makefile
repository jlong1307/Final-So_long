# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlong <jlong@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/30 12:03:07 by jlong             #+#    #+#              #
#    Updated: 2021/10/13 10:22:46 by jlong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			= 	source/so_long \
				source/get_next_line_utils \
				source/get_next_line \
				source/check_map \
				source/build_map \
				source/init \
				source/close_window \
				source/mouvement \
				source/mouvement_p \
				source/check_map2 \

SRCS		= $(addsuffix .c, ${SRC})

OBJS		= ${SRCS:.c=.o}
				
NAME		= so_long

CC			= gcc
RM			= rm -f
RN			= ranlib

CFLAGS		= -Wall -Wextra -Werror

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@			

$(NAME):	${OBJS}
			make -C libft
			make -C minilibx
			${CC} ${CFLAGS} ${OBJS} libft/libft.a libmlx.dylib -o ${NAME}
			
all:		$(NAME)

clean:
			make clean -C libft
			make clean -C minilibx
			${RM} ${OBJS}

fclean:		clean
			make fclean -C libft
			make clean -C minilibx
			${RM} $(NAME) libmlx.dylib

re:			fclean all

.PHONY:		all clean fclean re
