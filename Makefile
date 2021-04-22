# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/17 18:54:46 by thsembel          #+#    #+#              #
#    Updated: 2021/04/22 13:01:13 by thsembel         ###   ########.fr        #
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
				./srcs/nlist_compare.c \

SRCS_BONUS	=	./srcs_bonus/push_swap.c\
				./srcs_bonus/check_arg.c\
				./srcs_bonus/error.c\
				./srcs_bonus/utils.c\
				./srcs_bonus/algo.c \
				./srcs_bonus/is_sorted.c\
				./srcs_bonus/push_a_b.c \
				./srcs_bonus/rotate_a_b.c \
				./srcs_bonus/reverse_rot_a_b.c \
				./srcs_bonus/swap_a_b.c \
				./srcs_bonus/big_pile_algo.c \
				./srcs_bonus/median_rotation.c \
				./srcs_bonus/action_count.c \
				./srcs_bonus/choose_action.c \
				./srcs_bonus/nlist_compare.c \
				./srcs_bonus/display_bonus.c \
				./srcs_bonus/choose_action2.c

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

OBJS_B		= ${SRCS_BONUS:.c=.o}

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

bonus:		${OBJS_B}
			@${CC} ${CFLAGS} -I${HEAD} ${LIBFT} -o ${NAME} $(OBJS_B)
			@echo "${GREEN}pushswap	with bonus has been created\n${NC}"

clean:
			@make -C $(LIB_DIR) clean
			@${RM} ${OBJS} ${OBJS2} ${OBJS_B}
			@echo "${GREEN}[ OK ]${RED}	*.o files	deleted${NC}"

fclean:		clean
			@make -C $(LIB_DIR) fclean
			@echo "${GREEN}[ OK ]${RED}	libft.a		deleted${NC}"
			@${RM} ${NAME} ${NAME2}
			@echo "${GREEN}[ OK ]${RED}	pushswap	deleted${NC}"
			@echo "${GREEN}[ OK ]${RED}	checker		deleted\n${NC}"

re :		fclean all

.PHONY:		all	clean	fclean re

