/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_irc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 12:14:46 by cledant           #+#    #+#             */
/*   Updated: 2017/04/20 13:43:44 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_IRC_H
# define FT_IRC_H

# include <sys/select.h>
# include <sys/socket.h>
# include <sys/resource.h>
# include <sys/socket.h>
# include <sys/time.h>
# include <arpa/inet.h>
# include <signal.h>
# include <netdb.h>
# include <stdio.h>
# include <curses.h>
# include "libft.h"

# define MAX_PACKET_SIZE 1024
# define MAX_MSG_LEN 512
# define LISTEN_SIZE 128
# define MAX_NICK_LEN 9
# define MAX_NB_CHAN 128
# define MAX_CHAN_NAME_LEN 50
# define MAX_CMD_SIZE 20
# define BEGIN_PACKET ":"
# define END_PACKET "\n"
# define CBUFF_SIZE 8192
# define DEFAULT_IP "localhost"
# define DEFAULT_PORT "4242"
# define CLNT_BEGIN_CMD "/"
# define CLNT_END_CMD "\n"
# define CLNT_END_CMD_CHAR '\n'

# define FD_NEW_DATA 1
# define FD_NO_DATA 0

# define IN_CHAN 1
# define NOT_IN_CHAN 0

# define FREE 1
# define NO_FREE 0

# define CONNECTED 1
# define DISCONNECTED 0

typedef enum		e_err
{
	ERR_NB_ARG,
	ERR_ARG_NOT_INT,
	ERR_PORT_INTERVAL,
	ERR_GET_RLIM,
	ERR_MAX_FD,
	ERR_ALLOC_MEM,
	ERR_UNKNOWN_PROTOCOL,
	ERR_OPEN_SOCKET,
	ERR_BIND_SOCKET,
	ERR_LISTEN_SOCKET,
	ERR_CLOSE_DISCONNECTED,
	ERR_CLOSE_OVERWRITE,
	ERR_CLOSE_INIT_NAME,
	ERR_MAX_CHAN,
	ERR_CHAN_NAME,
	ERR_USER_ALREADY_IN_CHAN,
	ERR_USER_NOT_IN_CHAN,
	ERR_CHAN_DOES_NOT_EXIST,
	ERR_FIRST_ARG,
	ERR_SECOND_ARG,
	ERR_INVALID_CHAN_USER,
	ERR_MAX_CHAN_USER_LEN,
	ERR_SERV_NOT_FOUND,
	ERR_SERV_CONNECT,
	ERR_INIT_NCURSES,
	ERR_NONE,
}					t_err;

typedef enum		e_type
{
	FD_FREE,
	FD_SERVER,
	FD_CLIENT,
}					t_type;

typedef enum		e_chan_state
{
	CHAN_IN_USE,
	CHAN_FREE,
}					t_chan_state;

typedef enum		e_switch
{
	SET,
	RESET,
}					t_switch;

typedef enum		e_target
{
	TARGET_CHAN,
	TARGET_USER,
	TARGET_SENDER,
	TARGET_USER_AND_SENDER,
	ONE_TIME_TO_USER_WITH_COMMON_CHAN,
	TARGET_CHAN_AND_SENDER,
	NO_TARGET,
}					t_target;

typedef enum		e_func
{
	NICK,
	JOIN,
	PART,
	NAMES,
	PRIVMSG,
	WELCOME,
	SMSG,
	QUIT,
	NO_FUNCTION,
}					t_func;

typedef enum		e_privmsg_type
{
	IS_CHAN,
	IS_USER,
	NOTHING = 0,
}					t_privmsg_type;

typedef struct		s_cbuff
{
	size_t			size;
	size_t			r_pos;
	size_t			w_pos;
	size_t			enqueue_cumul;
	size_t			overwrite;
	char			*buff;
	char			*enqueue_buff;
	char			*dequeue_buff;
}					t_cbuff;

typedef struct		s_fd
{
	t_type			type;
	char			nick[MAX_NICK_LEN + 1];
	char			joined_chan[MAX_NB_CHAN];
	void			(*fct_read)();
	void			(*fct_write)();
	t_cbuff			*cbuff_read;
	t_cbuff			*cbuff_write;
}					t_fd;

typedef	struct		s_chan
{
	t_chan_state	state;
	char			name[MAX_CHAN_NAME_LEN + 1];
	size_t			nb_user;
}					t_chan;

typedef struct		s_cmd
{
	t_func			function;
	t_target		target;
	int				fd_sender;
	int				fd_target;
	int				id_chan;
	char			cmd[MAX_PACKET_SIZE + 1];
}					t_cmd;

typedef struct		s_disp_cmd
{
	t_func			function;
	char			nick[MAX_NICK_LEN + 1];
	char			msg_chan[MAX_CHAN_NAME_LEN + 1];
	char			msg_nick[MAX_NICK_LEN + 1];
	char			msg[MAX_PACKET_SIZE + 1];
}					t_disp_cmd;

typedef struct		s_env
{
	t_fd			*list_fd;
	char			*new_data;
	int				max_fd;
	int				port;
	size_t			should_loop;
	fd_set			fdset_r;
	fd_set			fdset_w;
	int				select_max;
	int				select_do;
	char			*file_name;
	t_chan			list_chan[MAX_NB_CHAN];
}					t_env;

typedef struct		s_clnt_env
{
	int				max_fd;
	int				socket;
	int				port;
	int				state;
	int				select_max;
	struct addrinfo	*result;
	WINDOW			*in;
	WINDOW			*out;
	int				select_do;
	fd_set			fdset_r;
	fd_set			fdset_w;
	char			buff[MAX_MSG_LEN + 1];
	t_cbuff			*cbuff_read;
	t_cbuff			*cbuff_write;
	int				should_loop;
	char			*file_name;
	char			last_chan[MAX_CHAN_NAME_LEN + 1];
}					t_clnt_env;

typedef struct		s_cmd_arg
{
	char			*begin;
	char			*end;
}					t_cmd_arg;

typedef struct		s_privmsg
{
	char			buffer[MAX_PACKET_SIZE + 1];
	char			user_name[MAX_NICK_LEN + 1];
	char			chan_name[MAX_CHAN_NAME_LEN + 1];
	char			msg_content[MAX_MSG_LEN + 1];
	t_cmd_arg		first_arg;
	t_privmsg_type	type;
	size_t			buffer_size;
	size_t			first_arg_size;
	size_t			second_arg_size;
}					t_privmsg;

typedef struct		s_userlist
{
	char			chan_name[MAX_CHAN_NAME_LEN + 1];
	int				chan_id;
	int				nb_user;
	char			user_list[MAX_MSG_LEN + 1];
}					t_userlist;

/*
**	CIRCULAR BUFFER FUNCTIONS
*/
t_cbuff				*cbuff_create(const size_t buff_size);
void				cbuff_destroy(t_cbuff **cbuff);
size_t				cbuff_enqueue(t_cbuff *cbuff, const size_t e_size);
size_t				cbuff_dequeue(t_cbuff *cbuff, const size_t d_size);
size_t				cbuff_dequeue_till_head_no_change(t_cbuff *cbuff);
void				cbuff_flush(t_cbuff *cbuff);
void				cbuff_move_forward_read_head(t_cbuff *cbuff,
						const size_t f_size);

/*
**	SERVER FUNCTIONS
*/
t_env				*srv_get_env(t_env *env);
void				srv_set_signal(void);
void				srv_shutdown(void);
t_err				srv_init_env(t_env *env, char **argv);
void				srv_close_all_client_socket(t_env *env);
void				srv_close_srv_socket(t_env *env);
int					srv_init_fd_free(t_fd *fd, const t_switch type);
void				srv_init_fd_client(t_env *env, const int fd_sock);
void				srv_destroy_fd(t_env *env);
void				srv_init_chan_free(t_chan *chan);
t_err				srv_create_server(t_env *env);
void				srv_main_loop(t_env *env);
void				srv_set_fd_select(t_env *env);
void				srv_do_select(t_env *env);
void				srv_check_fd_select(t_env *env);
void				srv_accept_new_client(t_env *env, int fd_sock);
void				srv_client_read(t_env *env, int fd_sock);
void				srv_client_write(t_env *env, int fd_sock);
void				srv_disconnect_client(t_env *env, const int fd_sock,
						const t_err err);
int					srv_set_first_nick(t_env *env, const int fd_sock);
int					srv_is_nick_free(t_env *env, const int fd_sock,
						const char *nick);
void				srv_interpret_new_data(t_env *env);
int					srv_create_cmd(t_env *env, const int fd_sock, t_cmd *cmd);
int					srv_is_cmd_valid(const char *cmd_str, t_cmd *cmd);
int					srv_is_str_a_cmd(const char *str);
void				srv_execute_cmd(t_env *env, t_cmd *cmd);
int					srv_has_sender_target_common_chan(t_env *env,
						const int fd_target, const int fd_sender);
int					srv_join_user_to_channel(t_env *env, const int fd_sock,
						const char *chan_name);
int					srv_seek_user_fd(t_env *env, const char *user_name);
int					srv_seek_chan_id(t_env *env, const char *chan_name);
int					srv_seek_new_chan_slot(t_env *env);
int					srv_part_user_to_channel(t_env *env, const int fd_sock,
						const char *chan_name);
void				srv_notify_quit_common_chan(t_env *env, const int fd_stock,
						const char *reason);
void				srv_seek_userlist(t_env *env, t_userlist *u_list);
void				srv_itoa_buffer(int n, char *buffer);

/*
** SERVER COMMAND FUNCTIONS
*/
int					srv_cmd_nick(t_cmd *cmd, const t_cmd_arg *arg, t_env *env,
						const int fd_sock);
int					srv_cmd_join(t_cmd *cmd, const t_cmd_arg *arg, t_env *env,
						const int fd_sock);
int					srv_cmd_part(t_cmd *cmd, const t_cmd_arg *arg, t_env *env,
						const int fd_sock);
int					srv_cmd_quit(t_cmd *cmd, const t_cmd_arg *arg, t_env *env,
						const int fd_sock);
int					srv_cmd_privmsg(t_cmd *cmd, const t_cmd_arg *arg,
						t_env *env, const int fd_sock);
int					srv_cmd_names(t_cmd *cmd, const t_cmd_arg *arg,
						t_env *env, const int fd_sock);

/*
** SERVER COMUNICATION FUNCTIONS
*/
int					srv_com_write_welcome(t_env *env, const int fd_sock);
void				srv_com_one_time_common_chan(t_env *env, t_cmd *cmd);
void				srv_com_send_to_sender(t_env *env, t_cmd *cmd);
void				srv_com_send_to_user(t_env *env, t_cmd *cmd);
void				srv_com_send_to_target_chan(t_env *env, t_cmd *cmd);
void				srv_com_send_to_target_chan_and_sender(t_env *env,
						t_cmd *cmd);

/*
** CLIENT FUNCTIONS
*/
t_err				clnt_init_env(t_clnt_env *env, char **argv);
t_clnt_env			*clnt_get_env(t_clnt_env *env);
void				clnt_destroy_env(t_clnt_env *env);
t_err				clnt_init_ncurses(t_clnt_env *env);
void				clnt_close_ncurses(t_clnt_env *env);
t_err				clnt_connect_server(const char *addr, const char *port,
						t_clnt_env *env);
void				clnt_disconnect(t_clnt_env *env);
void				clnt_main_loop(t_clnt_env *env);
void				clnt_set_fd_select(t_clnt_env *env);
void				clnt_do_select(t_clnt_env *env);
void				clnt_check_fd_select(t_clnt_env *env);
void				clnt_read(t_cbuff *cbuff_read, int fd_sock,
						t_clnt_env *env);
void				clnt_write(t_cbuff *cbuff_write, int fd_sock,
						t_clnt_env *env);
void				clnt_interpret_new_data(t_clnt_env *env);
void				clnt_set_signal(void);
void				clnt_close_client(void);
int					clnt_interpret_prompt_cmd(t_clnt_env *env);
int					clnt_interpret_server_cmd(t_clnt_env *env);
int					clnt_read_cmd_server(t_clnt_env *env, t_disp_cmd *cmd);
int					clnt_is_str_online_only_cmd(const char *cmd_str);
int					clnt_disp_first_cmd_check(const char *cmd_str,
						t_disp_cmd *cmd, const t_cmd_arg *arg);
int					clnt_disp_second_cmd_check(t_disp_cmd *cmd,
						const t_cmd_arg *arg);

/*
** CLIENT COMMAND FUNCTIONS
*/
int					clnt_cmd_connect(const t_cmd_arg *arg, t_clnt_env *env);
int					clnt_cmd_disconnect(const t_cmd_arg *arg, t_clnt_env *env);
int					clnt_cmd_exit(const t_cmd_arg *arg, t_clnt_env *env);
int					clnt_cmd_nick(const t_cmd_arg *arg, t_clnt_env *env);
int					clnt_cmd_join(const t_cmd_arg *arg, t_clnt_env *env);
int					clnt_cmd_leave(const t_cmd_arg *arg, t_clnt_env *env);
int					clnt_cmd_quit(const t_cmd_arg *arg, t_clnt_env *env);
int					clnt_cmd_who(const t_cmd_arg *arg, t_clnt_env *env);
int					clnt_cmd_msg(const t_cmd_arg *arg, t_clnt_env *env);

/*
** CLIENT PARSE SERVER MSG FUNCTIONS
*/
int					clnt_parse_smsg(const t_cmd_arg *arg, t_disp_cmd *cmd);

/*
** CLIENT DISPLAY SERVER MSG FUNCTIONS
*/
int					clnt_disp_smsg(const t_disp_cmd *cmd, t_clnt_env *env);
int					clnt_disp_welcome(const t_disp_cmd *cmd, t_clnt_env *env);

#endif
