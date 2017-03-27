/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_init_fd_client.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 14:59:35 by cledant           #+#    #+#             */
/*   Updated: 2017/03/27 15:16:04 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

void		srv_init_fd_client(t_env *env, const int fd_sock)
{
	env->list_fd[fd_sock].type = FD_CLIENT;
	env->list_fd[fd_sock].fct_read = srv_client_read;
	env->list_fd[fd_sock].fct_write = srv_client_write;
	ft_bzero(env->list_fd[fd_sock].nick, MAX_NICK_LEN + 1);
	ft_bzero(env->list_fd[fd_sock].joined_chan, MAX_NB_CHAN);
	cbuff_flush(env->list_fd[fd_sock].cbuff_read);
	cbuff_flush(env->list_fd[fd_sock].cbuff_write);
	if (srv_set_first_nick(env, fd_sock) == 0)
		srv_disconnect_client(env, fd_sock, ERR_CLOSE_INIT_NAME);
	srv_com_write_welcome(env, fd_sock);
}
