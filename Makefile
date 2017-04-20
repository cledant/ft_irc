# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cledant <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/26 10:40:13 by cledant           #+#    #+#              #
#    Updated: 2017/04/20 17:04:44 by cledant          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Werror -Wall -Wextra -O2 -fsigned-char

OBJ_DIR_NAME = obj

OBJ_DIR_NAME_SERVEUR = $(OBJ_DIR_NAME)/srv

OBJ_DIR_NAME_CLIENT = $(OBJ_DIR_NAME)/clnt

OBJ_DIR_NAME_CBUFF = $(OBJ_DIR_NAME)/cbuff

LIBS = -lft

LIBS_CLNT = -lft -lncurses

INCLUDES = ./includes

INCLUDES_LIBFT = ./libft/includes

LIBFT_PATH = ./libft

SRCS_NAME_SERVEUR = main.c srv_client_write.c srv_init_fd_client.c \
					srv_accept_new_client.c srv_create_server.c srv_init_fd_free.c \
					srv_check_fd_select.c srv_do_select.c srv_main_loop.c \
					srv_client_read.c srv_init_env.c srv_set_fd_select.c \
					srv_init_chan_free.c srv_set_first_nick.c srv_is_nick_free.c \
					srv_com_write_welcome.c srv_interpret_new_data.c \
					srv_disconnect_client.c srv_create_cmd.c srv_is_cmd_valid.c \
					srv_cmd_nick.c srv_execute_cmd.c srv_com_one_time_common_chan.c \
					srv_has_sender_target_common_chan.c srv_com_send_to_sender.c \
					srv_is_str_a_cmd.c srv_cmd_join.c srv_seek_chan_id.c \
					srv_join_user_to_channel.c srv_seek_new_chan_slot.c \
					srv_com_send_to_target_chan.c srv_cmd_part.c \
					srv_part_user_to_channel.c srv_cmd_quit.c \
					srv_com_send_to_target_chan_and_sender.c \
					srv_notify_quit_common_chan.c srv_cmd_quit.c srv_cmd_privmsg.c \
					srv_seek_user_fd.c srv_com_send_to_user.c srv_get_env.c \
					srv_set_signal.c srv_shutdown.c srv_destroy_fd.c \
					srv_close_srv_socket.c srv_close_all_client_socket.c \
					srv_cmd_names.c srv_seek_userlist.c srv_itoa_buffer.c

SRCS_PATH_SERVEUR = ./srcs/srv

OBJ_SRCS_SERVEUR = $(SRCS_NAME_SERVEUR:%.c=$(OBJ_DIR_NAME_SERVEUR)/%.o)

NAME_SERVEUR = serveur

SRCS_NAME_CLIENT = main.c clnt_init_env.c clnt_connect_server.c clnt_init_ncurses.c \
				   clnt_main_loop.c clnt_set_fd_select.c clnt_do_select.c \
				   clnt_check_fd_select.c clnt_read.c clnt_write.c \
				   clnt_interpret_prompt_cmd.c clnt_interpret_server_cmd.c \
				   clnt_disconnect.c clnt_get_env.c clnt_destroy_env.c \
				   clnt_close_ncurses.c clnt_set_signal.c clnt_close_client.c \
				   clnt_cmd_connect.c clnt_cmd_disconnect.c clnt_cmd_exit.c \
				   clnt_cmd_nick.c clnt_cmd_join.c clnt_cmd_leave.c clnt_cmd_quit.c \
				   clnt_cmd_who.c clnt_cmd_msg.c clnt_is_str_online_only_cmd.c \
				   clnt_read_cmd_server.c clnt_disp_first_cmd_check.c \
				   clnt_parse_smsg.c clnt_disp_smsg.c clnt_disp_second_cmd_check.c \
				   clnt_disp_welcome.c clnt_disp_nick.c clnt_check_other_cmd.c \
				   clnt_parse_nick_join_part_quit.c clnt_disp_join.c \
				   clnt_disp_part.c clnt_disp_quit.c

SRCS_PATH_CLIENT = ./srcs/clnt

OBJ_SRCS_CLIENT = $(SRCS_NAME_CLIENT:%.c=$(OBJ_DIR_NAME_CLIENT)/%.o)

NAME_CLIENT = client

SRCS_NAME_CBUFF = cbuff_create.c cbuff_destroy.c cbuff_flush.c cbuff_enqueue.c \
				  cbuff_dequeue.c cbuff_dequeue_till_head_no_change.c \
				  cbuff_move_forward_read_head.c

SRCS_PATH_CBUFF = ./srcs/cbuff

OBJ_SRCS_CBUFF = $(SRCS_NAME_CBUFF:%.c=$(OBJ_DIR_NAME_CBUFF)/%.o)

all : libft $(NAME_SERVEUR) $(NAME_CLIENT)

libft :
	make -C $(LIBFT_PATH)

$(NAME_SERVEUR) : $(OBJ_SRCS_SERVEUR) $(OBJ_SRCS_CBUFF)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS) -L$(LIBFT_PATH)

$(NAME_CLIENT) : $(OBJ_SRCS_CLIENT) $(OBJ_SRCS_CBUFF)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS_CLNT) -L$(LIBFT_PATH)

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
