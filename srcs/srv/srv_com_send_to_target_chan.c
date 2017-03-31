/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_com_send_to_target_chan.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 18:27:46 by cledant           #+#    #+#             */
/*   Updated: 2017/03/31 12:14:21 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

void		srv_com_send_to_target_chan(t_env *env, t_cmd *cmd)
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
}
