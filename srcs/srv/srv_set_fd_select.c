/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_set_fd_select.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 15:22:48 by cledant           #+#    #+#             */
/*   Updated: 2017/03/29 03:16:45 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

void	srv_set_fd_select(t_env *env)
{
	int		c;

	c = 0;
	env->select_max = 0;
	FD_ZERO(&(env->fdset_r));
	FD_ZERO(&(env->fdset_w));
	while (c < env->max_fd)
	{
		if (env->list_fd[c].type == FD_CLIENT)
		{
			FD_SET(c, &(env->fdset_r));
			if (env->list_fd[c].cbuff_write->enqueue_cumul > 0)
				FD_SET(c, &(env->fdset_w));
			env->select_max = ft_max(c, env->select_max);
		}
		else if (env->list_fd[c].type == FD_SERVER)
		{
			FD_SET(c, &(env->fdset_r));
			env->select_max = ft_max(c, env->select_max);
		}
		c++;
	}
}
