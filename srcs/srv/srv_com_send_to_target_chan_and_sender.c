/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_com_send_to_target_chan_and_sender.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 13:06:48 by cledant           #+#    #+#             */
/*   Updated: 2017/03/30 13:06:57 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

void		srv_com_send_to_target_chan_and_sender(t_env *env, t_cmd *cmd)
{
	size_t		c;
	
	c = 0;
	while (c < (size_t)env->max_fd)
	{
		if (env->list_fd[c].type == FD_CLIENT &&
				env->list_fd[c].joined_chan[cmd->id_chan] == IN_CHAN)
		{
			ft_memcpy(env->list_fd[c].cbuff_write->enqueue_buff, cmd->cmd,
				ft_strlen(cmd->cmd));
			cbuff_enqueue(env->list_fd[c].cbuff_write, ft_strlen(cmd->cmd));
		}
		c++;
	}
	ft_memcpy(env->list_fd[cmd->fd_sender].cbuff_write->enqueue_buff,
		cmd->cmd, MAX_PACKET_SIZE + 1);
	cbuff_enqueue(env->list_fd[cmd->fd_sender].cbuff_write,
		ft_strlen(cmd->cmd));
}
