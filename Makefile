# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cledant <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/26 10:40:13 by cledant           #+#    #+#              #
#    Updated: 2017/03/25 11:39:14 by cledant          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Werror -Wall -Wextra -O2 -fsigned-char

OBJ_DIR_NAME = obj

OBJ_DIR_NAME_SERVEUR = $(OBJ_DIR_NAME)/srv

OBJ_DIR_NAME_CLIENT = $(OBJ_DIR_NAME)/clnt

OBJ_DIR_NAME_CBUFF = $(OBJ_DIR_NAME)/cbuff

LIBS = -lft

INCLUDES = ./includes

INCLUDES_LIBFT = ./libft/includes

LIBFT_PATH = ./libft

SRCS_NAME_SERVEUR = main.c srv_client_write.c srv_init_fd_client.c \
					srv_accept_new_client.c srv_create_server.c srv_init_fd_free.c \
					srv_check_fd_select.c srv_do_select.c srv_main_loop.c \
					srv_client_read.c srv_init_env.c srv_set_fd_select.c

SRCS_PATH_SERVEUR = ./srcs/srv

OBJ_SRCS_SERVEUR = $(SRCS_NAME_SERVEUR:%.c=$(OBJ_DIR_NAME_SERVEUR)/%.o)

NAME_SERVEUR = serveur

SRCS_NAME_CLIENT = main.c

SRCS_PATH_CLIENT = ./srcs/clnt

OBJ_SRCS_CLIENT = $(SRCS_NAME_CLIENT:%.c=$(OBJ_DIR_NAME_CLIENT)/%.o)

NAME_CLIENT = client

SRCS_NAME_CBUFF = cbuff_create.c cbuff_destroy.c cbuff_flush.c cbuff_enqueue.c \
				  cbuff_dequeue.c cbuff_dequeue_till_head_no_change.c

SRCS_PATH_CBUFF = ./srcs/cbuff

OBJ_SRCS_CBUFF = $(SRCS_NAME_CBUFF:%.c=$(OBJ_DIR_NAME_CBUFF)/%.o)

all : libft $(NAME_SERVEUR) $(NAME_CLIENT)

libft :
	make -C $(LIBFT_PATH)

$(NAME_SERVEUR) : $(OBJ_SRCS_SERVEUR) $(OBJ_SRCS_CBUFF)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS) -L$(LIBFT_PATH)

$(NAME_CLIENT) : $(OBJ_SRCS_CLIENT) $(OBJ_SRCS_CBUFF)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS) -L$(LIBFT_PATH)

$(OBJ_DIR_NAME_SERVEUR)/%.o : $(SRCS_PATH_SERVEUR)/%.c
	mkdir -p $(OBJ_DIR_NAME_SERVEUR)
	$(CC) -o $@ -c $< $(CFLAGS) -I$(INCLUDES) -I$(INCLUDES_LIBFT)

$(OBJ_DIR_NAME_CLIENT)/%.o : $(SRCS_PATH_CLIENT)/%.c
	mkdir -p $(OBJ_DIR_NAME_CLIENT)
	$(CC) -o $@ -c $< $(CFLAGS) -I$(INCLUDES) -I$(INCLUDES_LIBFT)

$(OBJ_DIR_NAME_CBUFF)/%.o : $(SRCS_PATH_CBUFF)/%.c
	mkdir -p $(OBJ_DIR_NAME_CBUFF)
	$(CC) -o $@ -c $< $(CFLAGS) -I$(INCLUDES) -I$(INCLUDES_LIBFT)

clean :
	rm -rf $(OBJ_DIR_NAME)
	make -C $(LIBFT_PATH) clean

fclean : clean
	rm -rf $(NAME_SERVEUR)
	rm -rf $(NAME_CLIENT)
	make -C $(LIBFT_PATH) fclean

re : fclean all

.PHONY : all clean fclean re libft
