/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_interpret_new_data.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 10:25:00 by cledant           #+#    #+#             */
/*   Updated: 2017/03/28 17:55:05 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

static inline void		init_cmd(t_cmd *cmd)
{
	cmd->target = NO_TARGET;
	cmd->function = NO_FUNCTION;
	cmd->fd_target = -1;
	cmd->fd_sender = -1;
	cmd->id_chan = -1;
	ft_bzero(cmd->cmd, MAX_PACKET_SIZE + 1);
}

void					srv_interpret_new_data(t_env *env)
{
	size_t		i;
	t_cmd		cmd;

	i = 0;
	while (i < (size_t)env->max_fd)
	{
		init_cmd(&cmd);
		if (env->new_data[i] == FD_NEW_DATA)
		{
			if (env->list_fd[i].cbuff_read->overwrite == 1)
				srv_disconnect_client(env, i, ERR_CLOSE_OVERWRITE);
			else
			{
				while (srv_create_cmd(env, i, &cmd) == 1)
				{
					srv_execute_cmd(env, &cmd);
					init_cmd(&cmd);
				}
			}
			env->new_data[i] = FD_NO_DATA;
		}
		i++;
	}
}
