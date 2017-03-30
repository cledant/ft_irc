/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_client_read.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 20:07:18 by cledant           #+#    #+#             */
/*   Updated: 2017/03/30 14:27:04 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

static inline void		notify_common_chan(t_env *env, int fd_sock)
{
	t_cmd		cmd;
	

	cmd.function = SMSG;
	cmd.target = ONE_TIME_TO_USER_WITH_COMMON_CHAN;
	cmd.fd_target = -1;
	cmd.fd_sender = fd_sock;
	cmd.id_chan = -1;
	ft_bzero(cmd.cmd, MAX_PACKET_SIZE + 1);
	ft_strcat(cmd.cmd, BEGIN_PACKET);
	ft_strcat(cmd.cmd, env->list_fd[fd_sock].nick);
	ft_strcat(cmd.cmd, " QUIT");
	ft_strcat(cmd.cmd, END_PACKET);
	srv_com_one_time_common_chan(env, &cmd);
}

void					srv_client_read(t_env *env, int fd_sock)
{
	int		rvd;

	if ((rvd = recv(fd_sock, env->list_fd[fd_sock].cbuff_read->enqueue_buff,
			CBUFF_SIZE, 0)) <= 0)
	{
		notify_common_chan(env, fd_sock);
		srv_disconnect_client(env, fd_sock, ERR_CLOSE_DISCONNECTED);
		return ;
	}
	printf("%s : Client ID : %d sent a packet of %d bytes !\n",
		env->file_name, fd_sock, rvd);
	cbuff_enqueue(env->list_fd[fd_sock].cbuff_read, rvd);
	env->new_data[fd_sock] = FD_NEW_DATA;
}
