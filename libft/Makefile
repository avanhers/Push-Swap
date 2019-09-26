# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avanhers <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/02 15:56:59 by avanhers          #+#    #+#              #
#    Updated: 2019/08/06 07:54:37 by avanhers         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a
FLAGS = -Wall -Werror -Wextra

SRC_NAME = ft_bzero.c \
		   ft_putchar.c \
		   ft_putendl.c \
		   ft_putchar_fd.c \
		   ft_putstr_fd.c \
		   ft_putendl_fd.c \
		   ft_putnbr.c \
		   ft_putstr.c \
		   ft_strcmp.c \
		   ft_strlen.c \
		   ft_atoi.c \
		   ft_isdigit.c	\
		   ft_strequ.c \
		   gnl_wnl.c \
		   ft_strchr.c \
		   ft_strdup.c \
		   ft_strclr.c \
		   ft_strdel.c \
		   free_gnl.c	\
		   ft_strjoin.c \
		   ft_strncpy.c \
		   ft_strnew.c \
		   ft_strnequ.c\
		   ft_strsub.c\
		   ft_lstnew.c\
		   ft_lstadd.c\
		   ft_lst_remove_if.c\
		   ft_memcpy.c		\
		   ft_error.c		\
		   ft_strsplit.c

SRC_DIR = src
BUILD_DIR = obj
INC_DIR = inc

OBJ = $(addprefix $(BUILD_DIR)/,$(SRC_NAME:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[2K \033[A"
	@ar rc $(NAME) $(OBJ)
	@echo "\033[32m[$(NAME)]: compiled\033[0m"

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	@echo "\033[2K [$(NAME)]: Compilation of $< \033[A"
	@gcc $(CFLAGS) -I $(INC_DIR) -c $< -o $@

clean:
	@rm -rf $(BUILD_DIR)
	@echo "\033[33m[$(NAME)]: OBJ deleted\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[31m[$(NAME)]: deleted\033[0m"

re: fclean all
