# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/17 18:54:46 by thsembel          #+#    #+#              #
#    Updated: 2021/04/20 12:00:55 by thsembel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NC = \033[0m
RED = \033[0;91m
ORANGE = \033[93m
GREEN = \033[0;92m
PURPLE = \033[0;95m
BLUE = \033[0;34m
BOLD = \033[1m

SRCS		=	./srcs/push_swap.c\
				./srcs/check_arg.c\
				./srcs/error.c\
				./srcs/utils.c\
				./srcs/algo.c \
				./srcs/is_sorted.c\
				./srcs/push_a_b.c \
				./srcs/rotate_a_b.c \
				./srcs/reverse_rot_a_b.c \
				./srcs/swap_a_b.c \
				./srcs/big_pile_algo.c \
				./srcs/median_rotation.c \
				./srcs/action_count.c \
				./srcs/choose_action.c \
				./srcs/nlist_compare.c

SRCS2		=	./checker_srcs/utils.c \
				./checker_srcs/check_arg.c \
				./checker_srcs/error.c \
				./checker_srcs/push_a_b.c \
				./checker_srcs/rotate_a_b.c \
				./checker_srcs/reverse_rot_a_b.c \
				./checker_srcs/swap_a_b.c \
				./checker_srcs/checker.c \
				./checker_srcs/checker2.c

INCLUDES	=	./includes/libft.h \
				./includes/ft_printf.h \
				./includes/push_swap.h

HEAD		= ./includes/

LIBFT		= ./libft/libft.a

LIB_DIR	= ./libft/

NAME		= push_swap

NAME2		= checker

CC			= clang

OBJS		= ${SRCS:.c=.o}

OBJS2		= ${SRCS2:.c=.o}

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror -fsanitize=address

.c.o:
		@${CC} ${CFLAGS} -I${HEAD} -c $< -o ${<:.c=.o}
		@echo "${GREEN}[ OK ]	${ORANGE}${<:.s=.o}${NC}"


all:		${NAME} ${NAME2}

${NAME}:	${OBJS}
			@make -C ${LIB_DIR}
			@make -C ${LIB_DIR} bonus
			@echo "${GREEN}\nlibft.a		has been created"
			@${CC} ${CFLAGS} -I${HEAD} ${LIBFT} -o ${NAME} $(OBJS)
			@echo "pushswap	has been created\n${NC}"

${NAME2}:	${OBJS2}
			@${CC} ${CFLAGS} -I${HEAD} ${LIBFT} -o ${NAME2} $(OBJS2)
			@echo "${GREEN}\nchecker		has been created${NC}"

#all:		${NAME} ${NAME2}

clean:
			@make -C $(LIB_DIR) clean
			@${RM} ${OBJS} ${OBJS2}
			@echo "${GREEN}[ OK ]${RED}	*.o files	deleted${NC}"

fclean:		clean
			@make -C $(LIB_DIR) fclean
			@echo "${GREEN}[ OK ]${RED}	libft.a		deleted${NC}"
			@${RM} ${NAME} ${NAME2}
			@echo "${GREEN}[ OK ]${RED}	pushswap	deleted${NC}"
			@echo "${GREEN}[ OK ]${RED}	checker		deleted\n${NC}"

re :		fclean all

.PHONY:		all	clean	fclean re

