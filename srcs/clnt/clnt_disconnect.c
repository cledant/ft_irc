/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clnt_disconnect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 12:07:08 by cledant           #+#    #+#             */
/*   Updated: 2017/04/18 13:35:14 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

void	clnt_disconnect(t_clnt_env *env)
{
	if (env->state == CONNECTED)
		wprintw(env->out, "\nDisconnected from server !");
	env->state = DISCONNECTED;
	if (env->socket != 0)
		close(env->socket);
	cbuff_flush(env->cbuff_read);
	cbuff_flush(env->cbuff_write);
	env->port = 0;
	env->socket = 0;
	ft_bzero(&(env->buff), MAX_MSG_LEN + 1);
	ft_bzero(&(env->last_chan), MAX_CHAN_NAME_LEN + 1);
}
