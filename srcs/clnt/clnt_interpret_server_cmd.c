/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clnt_interpret_server_cmd.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 16:23:57 by cledant           #+#    #+#             */
/*   Updated: 2017/05/15 10:00:01 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

int		clnt_interpret_server_cmd(t_clnt_env *env)
{
	t_disp_cmd		cmd;
	int				loop;

	loop = 1;
	while (loop)
	{
		if (env->cbuff_read->overwrite == 1)
		{
			clnt_disconnect(env);
			return (0);
		}
		ft_bzero(&cmd, sizeof(t_disp_cmd));
		loop = clnt_read_cmd_server(env, &cmd);
	}
	return (1);
}
