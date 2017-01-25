# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cledant <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/26 10:40:13 by cledant           #+#    #+#              #
#    Updated: 2017/01/25 18:47:27 by cledant          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Werror -Wall -Wextra -O2 -fsigned-char

OBJ_DIR_NAME = obj

LIBS = -lft

INCLUDES = ./includes/otool

INCLUDES_LIBFT = ./libft/includes

LIBFT_PATH = ./libft

SRCS_NAME = otool.c otool_start.c

SRCS_PATH = ./srcs/otool

OBJ_SRCS = $(SRCS_NAME:%.c=$(OBJ_DIR_NAME)/%.o)

NAME = ft_otool

all :	libft $(OBJ_DIR_NAME) $(NAME)

libft :
	make -C $(LIBFT_PATH)

$(OBJ_DIR_NAME) :
	mkdir $(OBJ_DIR_NAME)

$(NAME) : $(OBJ_SRCS)
	$(CC) -shared -o $@ $^ $(CFLAGS) $(LIBS) -L$(LIBFT_PATH)

$(OBJ_DIR_NAME)/%.o : $(SRCS_PATH)/%.c
	$(CC) -o $@ -c $< $(CFLAGS) $(SHARED_CFLAGS) -I$(INCLUDES) -I$(INCLUDES_LIBFT)

clean :
	rm -rf $(OBJ_DIR_NAME)
	make -C $(LIBFT_PATH) clean

fclean : clean
	rm -rf $(NAME)
	rm -rf $(LINK)
	make -C $(LIBFT_PATH) fclean

re : fclean all

.PHONY : all clean fclean re libft
