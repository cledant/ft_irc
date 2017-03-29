/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_com_one_time_common_chan.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 12:39:03 by cledant           #+#    #+#             */
/*   Updated: 2017/03/29 03:14:08 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

void		srv_com_one_time_common_chan(t_env *env, t_cmd *cmd)
{
	size_t		c;

	c = 0;
	while (c < (size_t)env->max_fd)
	{
		if (env->list_fd[c].type == FD_CLIENT && (size_t)cmd->fd_sender != c)
		{
			if (srv_has_sender_target_common_chan(env, c, cmd->fd_sender) == 1)
			{
				ft_memcpy(env->list_fd[c].cbuff_write->enqueue_buff, cmd->cmd,
					MAX_PACKET_SIZE + 1);
				cbuff_enqueue(env->list_fd[c].cbuff_write,
					ft_strlen(env->list_fd[c].cbuff_write->enqueue_buff));
			}
		}
		else if ((size_t)cmd->fd_sender == c)
		{
			ft_memcpy(env->list_fd[c].cbuff_write->enqueue_buff, cmd->cmd,
				MAX_PACKET_SIZE + 1);
			cbuff_enqueue(env->list_fd[c].cbuff_write,
				ft_strlen(env->list_fd[c].cbuff_write->enqueue_buff));
		}
		c++;
	}
}
