/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clnt_check_fd_select.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 12:41:34 by cledant           #+#    #+#             */
/*   Updated: 2017/04/18 16:36:01 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

void		clnt_check_fd_select(t_clnt_env *env)
{
	size_t		end;

	if (FD_ISSET(0, &(env->fdset_r)))
	{
		wgetnstr(env->in, env->buff, MAX_MSG_LEN - 1);
		end = ft_strlen(env->buff);
		if (end > 0)
			env->buff[end] = '\n';
		wclear(env->in);
		wrefresh(env->in);
		(env->select_do)--;
	}
	if (env->state == CONNECTED && FD_ISSET(env->socket, &(env->fdset_r)))
	{
		clnt_read(env->cbuff_read, env->socket, env);
		(env->select_do)--;
	}
	if (env->state == CONNECTED && FD_ISSET(env->socket, &(env->fdset_w)))
	{
		clnt_write(env->cbuff_write, env->socket, env);
		(env->select_do)--;
	}
}
