/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_set_fd_select.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 15:22:48 by cledant           #+#    #+#             */
/*   Updated: 2017/04/17 12:30:30 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

void	clnt_set_fd_select(t_clnt_env *env)
{
	FD_ZERO(&(env->fdset_r));
	FD_ZERO(&(env->fdset_w));
	FD_SET(0, &(env->fdset_r));
	FD_SET(env->socket, &(env->fdset_r));
	if (env->cbuff_write->enqueue_cumul > 0)
		FD_SET(env->socket, &(env->fdset_w));
}
