/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_irc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 12:14:46 by cledant           #+#    #+#             */
/*   Updated: 2017/03/23 20:03:34 by cledant          ###   ########.fr       */
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

# define IRC_BUFF_SIZE 4096
# define LISTEN_SIZE 128
# define MAX_NICK_LEN 9
# define MAX_NB_CHAN 128
# define MAX_CHAN_NAME_LEN 128

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

typedef struct		s_fd
{
	t_type			type;
	char			nick[MAX_NICK_LEN + 1];
	char			join_chan[MAX_NB_CHAN];
	void			(*fct_read)();
	void			(*fct_write)();
	char			buff_read[IRC_BUFF_SIZE + 1];
	char			buff_write[IRC_BUFF_SIZE + 1];
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
