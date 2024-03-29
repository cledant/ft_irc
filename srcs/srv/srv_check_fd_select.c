/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_check_fd_select.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 17:03:44 by cledant           #+#    #+#             */
/*   Updated: 2017/03/29 12:25:36 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

void		srv_check_fd_select(t_env *env)
{
	int		c;

	c = 0;
	while (c < env->max_fd && env->select_do > 0)
	{
		if (FD_ISSET(c, &(env->fdset_r)))
		{
			env->list_fd[c].fct_read(env, c);
			(env->select_do)--;
		}
		if (FD_ISSET(c, &(env->fdset_w)))
		{
			env->list_fd[c].fct_write(env, c);
			(env->select_do)--;
		}
		c++;
	}
}
