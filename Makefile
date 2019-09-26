# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avanhers <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/06 10:31:39 by avanhers          #+#    #+#              #
#    Updated: 2019/08/06 15:02:31 by avanhers         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror
LIBFT_PATH	=	./libft/
INCL		=	./inc/

CFLAGS		=	-I$(LIBFT_PATH)inc/ -I $(INCL) $(FLAGS)


LINKS		=	-L $(LIBFT_PATH) -lft

####### CHECKER #######

NAME_CHK	=	checker
NAME_PSWAP	=	push_swap

### PATH ###

SRCS_PATH	=	src/

SRCS_BOTH	=	check_arg.c \
				elem.c\
				stack.c \
				op.c \
				utils.c \
				free.c \

SRCS_CHK	=	checker.c \
				find_instruction.c

SRCS_CHK2	=	$(addprefix $(SRCS_PATH)src_check/, $(SRCS_CHK)) \
				$(addprefix $(SRCS_PATH), $(SRCS_BOTH))

SRCS_PSWAP	=	push_swap.c \
				insert.c	\
				print.c		\
				do_op.c		\
				sort_small.c

SRCS_PSWAP2	=	$(addprefix $(SRCS_PATH)src_pswap/, $(SRCS_PSWAP)) \
				$(addprefix $(SRCS_PATH), $(SRCS_BOTH))

OBJ_CHK		=	$(SRCS_CHK2:.c=.o)
OBJ_PSWAP	=	$(SRCS_PSWAP2:.c=.o)

OBJ_PATH	=	$(OBJ_PSWAP) \
				$(OBJ_CHK)

######### RULES #######

all : libs $(NAME_CHK) $(NAME_PSWAP)

$(NAME_CHK) : libs $(OBJ_CHK)
	@$(CC) -o $(NAME_CHK) $(OBJ_CHK) $(CFLAGS) $(LINKS)

$(NAME_PSWAP) : libs $(OBJ_PSWAP)
	@$(CC) -o $(NAME_PSWAP) $(OBJ_PSWAP) $(CFLAGS) $(LINKS)


clean:
	@/bin/rm -rf $(OBJ_PATH)
	@make -C $(LIBFT_PATH) clean
	@echo "\033[31mObjects files \033[1;31m$(OBJS_LIST)\033[1;0m\033[31m removed.\033[0m"

fclean: clean
	@/bin/rm -rf $(NAME_CHK)
	@/bin/rm -rf $(NAME_PSWAP)
	@/bin/rm -rf $(LIBFT_PATH)libft.a
	@echo "\033[31mBin \033[1;31m$(NAME)\033[1;0m\033[31m removed.\033[0m"

re: fclean all

libs:
	@make -C $(LIBFT_PATH)

.PHONY: all re clean fclean libs
