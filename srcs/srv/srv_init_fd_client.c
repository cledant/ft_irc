/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_init_fd_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 19:34:54 by cledant           #+#    #+#             */
/*   Updated: 2017/03/25 18:08:54 by cledant          ###   ########.fr       */
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
	{
		close(fd_sock);
		srv_init_fd_free(&(env->list_fd[fd_sock]), RESET);
		printf("%s : New client ID : %d kicked : Can't find set init name !\n",
			env->file_name, fd_sock);
	}
	srv_com_write_welcome(env, fd_sock);
}
