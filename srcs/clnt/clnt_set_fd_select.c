/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clnt_set_fd_select.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 15:56:24 by cledant           #+#    #+#             */
/*   Updated: 2017/04/18 16:08:26 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

void	clnt_set_fd_select(t_clnt_env *env)
{
	FD_ZERO(&(env->fdset_r));
	FD_ZERO(&(env->fdset_w));
	FD_SET(0, &(env->fdset_r));
	env->select_max = 0;
	if (env->state == CONNECTED)
	{
		env->select_max = ft_max(0, env->socket);
		FD_SET(env->socket, &(env->fdset_r));
		if (env->cbuff_write->enqueue_cumul > 0)
			FD_SET(env->socket, &(env->fdset_w));
	}
}
