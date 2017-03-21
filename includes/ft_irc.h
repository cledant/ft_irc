/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_irc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 12:14:46 by cledant           #+#    #+#             */
/*   Updated: 2017/03/21 19:11:37 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_IRC_H
# define FT_IRC_H

# include <sys/select.h>
# include <sys/socket.h>
# include <sys/resource.h>
# include <sys/socket.h>
# include <arpa/inet.h>
# include <netdb.h>
# include "libft.h"

# define IRC_BUFF_SIZE 4096
# define LISTEN_SIZE 128
# define CHAN_BUFFER 128
# define MAX_CHAN_NB 128
# define MAX_CHAN_NAME_SIZE 32
# define MAX_CHAN_LINE_BUFF 64
# define MAX_CHAN_LINE_SIZE 256

typedef enum		s_err
{
	ERR_NB_ARG,
	ERR_ARG_NOT_INT,
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
	IRC_FREE,
	IRC_SERVER,
	IRC_CLIENT,
}					t_type;

typedef enum		s_chan_state
{
	CHAN_FREE,
	CHAN_USED,
}					t_chan_state;

typedef struct		s_fd
{
	t_type			type;
	char			nick[MAX_NICK_SIZE + 1];
	char			join_chan[MAX_CHAN_NB];
	size_t			cur_timeout;
	char			buff_read[IRC_BUFF_SIZE + 1];
	char			buff_write[IRC_BUFF_SIZE + 1];
}					t_fd;

typedef struct		s_chan_buffer
{
	char			buffer[MAX_CHAN_LINE_BUFF][MAX_CHAN_LINE_SIZE + 1];
	size_t			cur_line;
}					t_chan_buffer;

typedef struct		s_chan
{
	t_chan_state	state;
	char			name[MAX_CHAN_NAME_SIZE + 1];
	t_chan_buffer	buff;
}					t_chan;

typedef struct		s_env
{
	t_fd			*list_fd;
	int				maxfd;
	int				port;
	size_t			should_loop;
	fd_set			fdset_r;
	fd_set			fdset_w;
	t_chan			list_chan[MAX_CHAN_NB];
	size_t			cur_chan;
	size_t			max_timeout;
}					t_env;

t_err				irc_init_env(t_env *env, const char *argv);
void				irc_init_fd(t_fd *fd);
t_err				irc_create_server(t_env *env);
void				irc_main_loop(t_env *env);

#endif
