# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cledant <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/26 10:40:13 by cledant           #+#    #+#              #
#    Updated: 2017/01/26 17:16:12 by cledant          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Werror -Wall -Wextra -O2 -fsigned-char

OBJ_DIR_NAME = obj

OBJ_DIR_NAME_OTOOL = $(OBJ_DIR_NAME)/otool

LIBS = -lft

INCLUDES_OTOOL = ./includes/otool

INCLUDES_LIBFT = ./libft/includes

LIBFT_PATH = ./libft

SRCS_NAME_OTOOL = otool.c otool_start.c otool_macho_32.c otool_error_handler.c \
				  otool_init_info.c otool_set_endianness.c \
				  otool_is_mem_addr_valid.c

SRCS_PATH_OTOOL = ./srcs/otool

OBJ_SRCS_OTOOL = $(SRCS_NAME_OTOOL:%.c=$(OBJ_DIR_NAME_OTOOL)/%.o)

NAME_OTOOL = ft_otool

all : libft $(OBJ_DIR_NAME) $(OBJ_DIR_NAME_OTOOL) $(NAME_OTOOL)

libft :
	make -C $(LIBFT_PATH)

$(OBJ_DIR_NAME) :
	mkdir $(OBJ_DIR_NAME)

$(OBJ_DIR_NAME_OTOOL) :
	mkdir $(OBJ_DIR_NAME_OTOOL)

$(NAME_OTOOL) : $(OBJ_SRCS_OTOOL)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS) -L$(LIBFT_PATH)

$(OBJ_DIR_NAME_OTOOL)/%.o : $(SRCS_PATH_OTOOL)/%.c
	$(CC) -o $@ -c $< $(CFLAGS) -I$(INCLUDES_OTOOL) -I$(INCLUDES_LIBFT)

clean :
	rm -rf $(OBJ_DIR_NAME)
	make -C $(LIBFT_PATH) clean

fclean : clean
	rm -rf $(NAME)
	rm -rf $(LINK)
	make -C $(LIBFT_PATH) fclean

re : fclean all

.PHONY : all clean fclean re libft
