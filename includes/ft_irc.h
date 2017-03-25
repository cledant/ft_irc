/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_irc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 12:14:46 by cledant           #+#    #+#             */
/*   Updated: 2017/03/25 11:40:27 by cledant          ###   ########.fr       */
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
# include <netdb.h>
# include <stdio.h>
# include "libft.h"

# define MAX_PACKET_SIZE 1024
# define MAX_MSG_LEN 512
# define LISTEN_SIZE 128
# define MAX_NICK_LEN 9
# define MAX_NB_CHAN 128
# define MAX_CHAN_NAME_LEN 50
# define BEGIN_PACKET ":"
# define END_PACKET "\r\n"
# define CBUFF_SIZE 4096

typedef enum		s_err
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
	ERR_NONE,
}					t_err;

typedef enum		s_type
{
	FD_FREE,
	FD_SERVER,
	FD_CLIENT,
}					t_type;

typedef enum		s_chan_state
{
	CHAN_IN_USE,
	CHAN_FREE,
}					t_chan_state;

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
	t_cbuff			*cbuff;
}					t_fd;

typedef	struct		s_chan
{
	t_chan_state	state;
	char			name[MAX_CHAN_NAME_LEN];
	size_t			nb_user;
}					t_chan;

typedef struct		s_env
{
	t_fd			*list_fd;
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

/*
**	CIRCULAR BUFFER FUNCTIONS
*/
t_cbuff				*cbuff_create(const size_t buff_size);
void				cbuff_destroy(t_cbuff **cbuff);
size_t				cbuff_enqueue(t_cbuff *cbuff, const size_t e_size);
size_t				cbuff_dequeue(t_cbuff *cbuff, const size_t d_size);
size_t				cbuff_dequeue_till_head_no_change(t_cbuff *cbuff);
void				cbuff_flush(t_cbuff *cbuff);

/*
**	SERVER FUNCTIONS
*/
t_err				srv_init_env(t_env *env, char **argv);
void				srv_init_fd_free(t_fd *fd);
void				srv_init_fd_client(t_fd *fd);
t_err				srv_create_server(t_env *env);
void				srv_main_loop(t_env *env);
void				srv_set_fd_select(t_env *env);
void				srv_do_select(t_env *env);
void				srv_check_fd_select(t_env *env);
void				srv_accept_new_client(t_env *env, int fd_sock);
void				srv_client_read(t_env *env, int fd_sock);
void				srv_client_write(t_env *env, int fd_sock);

#endif
