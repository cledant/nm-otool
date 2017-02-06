# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cledant <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/26 10:40:13 by cledant           #+#    #+#              #
#    Updated: 2017/02/06 14:20:29 by cledant          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Werror -Wall -Wextra -O2 -fsigned-char

OBJ_DIR_NAME = obj

OBJ_DIR_NAME_OTOOL = $(OBJ_DIR_NAME)/otool

OBJ_DIR_NAME_NM = $(OBJ_DIR_NAME)/nm

LIBS = -lft

INCLUDES_OTOOL = ./includes/otool

INCLUDES_NM = ./includes/nm

INCLUDES_LIBFT = ./libft/includes

LIBFT_PATH = ./libft

SRCS_NAME_OTOOL = otool.c otool_start.c otool_error_handler.c \
				  otool_init_info.c otool_set_endianness.c \
				  otool_is_interval_valid.c \
				  otool_itoa_base_stack.c otool_macho_64.c \
				  otool_check_section_64.c otool_display_sec_64_data.c \
				  otool_display_text_addr_64.c convert_endian.c \
				  otool_macho_32.c otool_check_section_32.c \
				  otool_display_sec_32_data.c otool_display_text_addr_32.c \
				  otool_archive.c otool_fat_arch.c otool_init_fat_info.c \
				  otool_check_fat_arch_x86_64.c otool_check_fat_arch_x86.c \
				  otool_fat_display_all.c otool_fat_display_one.c \
				  otool_get_long_name_size.c otool_get_header_size.c \
				  otool_get_nb_item.c otool_archive_explore.c \
				  otool_create_start_name.c otool_strnlen.c

SRCS_PATH_OTOOL = ./srcs/otool

OBJ_SRCS_OTOOL = $(SRCS_NAME_OTOOL:%.c=$(OBJ_DIR_NAME_OTOOL)/%.o)

NAME_OTOOL = ft_otool

SRCS_NAME_NM = nm.c nm_start.c nm_error_handler.c nm_init_info.c \
			   nm_is_interval_valid.c nm_set_endianness.c nm_macho_64.c \
			   nm_check_symtab_64.c nm_display_symtab_64.c nm_display_symtab_64.c \
			   nm_display_symbol_value_type_64.c nm_print_undefined_64.c \
			   nm_print_absolute_64.c nm_print_sect_64.c nm_print_unknown_64.c \
			   nm_display_addr_64.c nm_is_string_tab_valid.c nm_new_size_t_tab.c \
			   nm_sort_symtab_64.c convert_endian.c nm_init_symbol_info_64.c \
			   nm_macho_32.c nm_fat_arch.c nm_check_fat_arch_x86_64.c \
			   nm_init_fat_info.c nm_check_fat_arch_x86.c nm_fat_display_all.c \
			   nm_fat_display_one.c nm_archive.c nm_get_long_name_size.c \
			   nm_get_header_size.c nm_get_nb_item.c nm_archive_explore.c \
			   nm_create_start_name.c nm_strnlen.c nm_get_sect_type_64.c \
			   nm_print_error_64.c nm_check_symtab_32.c nm_display_symtab_32.c \
			   nm_display_symbol_value_type_32.c nm_init_symbol_info_32.c \
			   nm_display_addr_32.c nm_print_undefined_32.c \
			   nm_print_absolute_32.c nm_print_sect_32.c nm_print_unknown_32.c \
			   nm_print_error_32.c nm_get_sect_type_32.c nm_sort_symtab_32.c

SRCS_PATH_NM = ./srcs/nm

OBJ_SRCS_NM = $(SRCS_NAME_NM:%.c=$(OBJ_DIR_NAME_NM)/%.o)

NAME_NM = ft_nm

all : libft $(OBJ_DIR_NAME) $(OBJ_DIR_NAME_OTOOL) $(OBJ_DIR_NAME_NM) $(NAME_OTOOL) $(NAME_NM)


libft :
	make -C $(LIBFT_PATH)

$(OBJ_DIR_NAME) :
	mkdir $(OBJ_DIR_NAME)

$(OBJ_DIR_NAME_OTOOL) :
	mkdir $(OBJ_DIR_NAME_OTOOL)

$(OBJ_DIR_NAME_NM) :
	mkdir $(OBJ_DIR_NAME_NM)

$(NAME_OTOOL) : $(OBJ_SRCS_OTOOL)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS) -L$(LIBFT_PATH)

$(NAME_NM) : $(OBJ_SRCS_NM)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS) -L$(LIBFT_PATH)

$(OBJ_DIR_NAME_OTOOL)/%.o : $(SRCS_PATH_OTOOL)/%.c
	$(CC) -o $@ -c $< $(CFLAGS) -I$(INCLUDES_OTOOL) -I$(INCLUDES_LIBFT)

$(OBJ_DIR_NAME_NM)/%.o : $(SRCS_PATH_NM)/%.c
	$(CC) -o $@ -c $< $(CFLAGS) -I$(INCLUDES_NM) -I$(INCLUDES_LIBFT)

clean :
	rm -rf $(OBJ_DIR_NAME)
	make -C $(LIBFT_PATH) clean

fclean : clean
	rm -rf $(NAME_OTOOL)
	rm -rf $(NAME_NM)
	make -C $(LIBFT_PATH) fclean

re : fclean all

.PHONY : all clean fclean re libft
