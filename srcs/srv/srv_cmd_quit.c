/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_cmd_quit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 21:51:07 by cledant           #+#    #+#             */
/*   Updated: 2017/03/30 15:23:56 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

static int				set_error(t_cmd *cmd, const int fd_sock)
{
	cmd->function = SMSG;
	cmd->target = TARGET_SENDER;
	cmd->id_chan = -1;
	cmd->fd_target = -1;
	cmd->fd_sender = fd_sock;
	ft_strcat(cmd->cmd, BEGIN_PACKET);
	ft_strcat(cmd->cmd, "SMSG Invalid Reason !");
	ft_strcat(cmd->cmd, END_PACKET);
	return (1);
}

int						srv_cmd_quit(t_cmd *cmd, const t_cmd_arg *arg,
							t_env *env, const int fd_sock)
{
	size_t		arg_size;
	char		reason[MAX_MSG_LEN + 1];

	arg_size = arg->end - arg->begin - 6;
	if (arg->end == arg->begin + 6 || arg_size == 0 || arg_size > MAX_MSG_LEN)
		return (set_error(cmd, fd_sock));
	ft_bzero(reason, MAX_MSG_LEN + 1);
	ft_memcpy(reason, arg->begin + 6, arg_size);
	cmd->target = NO_TARGET;
	srv_notify_quit_common_chan(env, fd_sock, reason);
	srv_disconnect_client(env, fd_sock, ERR_CLOSE_DISCONNECTED);
	return (1);
}
