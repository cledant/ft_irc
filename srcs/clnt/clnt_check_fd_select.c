/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clnt_check_fd_select.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 12:41:34 by cledant           #+#    #+#             */
/*   Updated: 2017/04/17 12:56:21 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

void		clnt_check_fd_select(t_clnt_env *env)
{
	if (FD_ISSET(0, &(env->fdset_r)))
	{
		(env->select_do)--;
	}
	if (FD_ISSET(env->socket, &(env->fdset_r)))
	{
		(env->select_do)--;
	}
	if (FD_ISSET(0, &(env->fdset_w)))
	{
		(env->select_do)--;
	}
}
