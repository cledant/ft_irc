/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_part_user_to_channel.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 12:05:21 by cledant           #+#    #+#             */
/*   Updated: 2017/03/31 12:10:23 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

int			srv_part_user_to_channel(t_env *env, const int fd_sock,
				const char *chan_name)
{
	int		chan_id;

	if ((chan_id = srv_seek_chan_id(env, chan_name)) == -1)
		return (-1);
	if (env->list_fd[fd_sock].joined_chan[chan_id] == NOT_IN_CHAN)
		return (-2);
	env->list_chan[chan_id].nb_user -= 1;
	env->list_fd[fd_sock].joined_chan[chan_id] = NOT_IN_CHAN;
	if (env->list_chan[chan_id].nb_user == 0)
		srv_init_chan_free(&(env->list_chan[chan_id]));
	return (chan_id);
}
