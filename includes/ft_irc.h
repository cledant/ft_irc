/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_irc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 12:14:46 by cledant           #+#    #+#             */
/*   Updated: 2017/03/21 13:23:09 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_IRC_H
# define FT_IRC_H

# include <sys/select.h>
# include <sys/socket.h>
# include <sys/resource.h>
# include "libft.h"

# define IRC_BUFF_SIZE 4096

typedef enum		s_err
{
	ERR_NB_ARG,
	ERR_ARG_NOT_INT,
	ERR_GET_RLIM,
	ERR_MAX_FD,
	ERR_ALLOC_MEM,
	ERR_NONE,
}					t_err;

typedef enum		s_type
{
	IRC_FREE,
	IRC_SERVER,
	IRC_CLIENT,
}					t_type;

typedef struct		s_fd
{
	t_type			type;
	char			buff_read[IRC_BUFF_SIZE + 1];
	char			buff_write[IRC_BUFF_SIZE + 1];
}					t_fd;

typedef struct		s_env
{
	t_fd			*list_fd;
	int				port;
	int				maxfd;
	fd_set			fdset_r;
	fd_set			fdset_w;
}					t_env;

t_err				irc_init_env(t_env *env, const char *argv);

#endif
