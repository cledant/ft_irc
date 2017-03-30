/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_client_read.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 20:07:18 by cledant           #+#    #+#             */
/*   Updated: 2017/03/30 15:12:19 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

void					srv_client_read(t_env *env, int fd_sock)
{
	int		rvd;

	if ((rvd = recv(fd_sock, env->list_fd[fd_sock].cbuff_read->enqueue_buff,
			CBUFF_SIZE, 0)) <= 0)
	{
		srv_notify_quit_common_chan(env, fd_sock, "Max buffer reached !");
		srv_disconnect_client(env, fd_sock, ERR_CLOSE_DISCONNECTED);
		return ;
	}
	printf("%s : Client ID : %d sent a packet of %d bytes !\n",
		env->file_name, fd_sock, rvd);
	cbuff_enqueue(env->list_fd[fd_sock].cbuff_read, rvd);
	env->new_data[fd_sock] = FD_NEW_DATA;
}
