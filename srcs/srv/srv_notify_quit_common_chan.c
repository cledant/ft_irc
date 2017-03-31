/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_notify_quit_common_chan.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 14:40:39 by cledant           #+#    #+#             */
/*   Updated: 2017/03/31 12:18:14 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

void			srv_notify_quit_common_chan(t_env *env, const int fd_sock,
					const char *reason)
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
	ft_strcat(cmd.cmd, " QUIT ");
	ft_strcat(cmd.cmd, reason);
	ft_strcat(cmd.cmd, END_PACKET);
	srv_com_one_time_common_chan(env, &cmd);
}
