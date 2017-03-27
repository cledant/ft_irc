/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_interpret_new_data.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 10:25:00 by cledant           #+#    #+#             */
/*   Updated: 2017/03/27 21:15:39 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

void	srv_interpret_new_data(t_env *env)
{
	size_t		i;
	t_cmd		cmd;

	while (i < env->max_fd)
	{
		if (env->new_data[i] == NEW_DATA)
		{
			if (env->list_fd[i].cbuff_read->overwrite == 1)
				srv_disconnect_client(env, i, ERR_CLOSE_OVERWRITE);
			else
			{
				while (srv_create_cmd(env, i, &cmd) == 1)
					srv_execute_cmd(env, cmd);
			}
			env->new_data[i] == NO_DATA;
		}
		i++;
	}
}
