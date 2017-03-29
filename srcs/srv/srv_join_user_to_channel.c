/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_join_user_to_channel.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:51:07 by cledant           #+#    #+#             */
/*   Updated: 2017/03/29 18:57:51 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

int			srv_join_user_to_channel(t_env *env, const int fd_sock,
				const char *chan_name)
{
	int		chan_id;

	if ((chan_id = srv_seek_chan_id(env, chan_name)) == -1)
	{
		if ((chan_id = srv_seek_new_chan_slot(env)) == -1)
			return (-1);
		env->list_chan[chan_id].state = CHAN_IN_USE;
		env->list_chan[chan_id].nb_user = 0;
		ft_bzero(env->list_chan[chan_id].name, MAX_CHAN_NAME_LEN + 1);
		ft_memcpy(env->list_chan[chan_id].name, chan_name,
			ft_strlen(chan_name));
	}
	if (env->list_fd[fd_sock].joined_chan[chan_id] == IN_CHAN)
		return (-2);
	env->list_chan[chan_id].nb_user += 1;
	env->list_fd[fd_sock].joined_chan[chan_id] = IN_CHAN;
	return (chan_id);
}
