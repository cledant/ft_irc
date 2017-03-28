/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_has_sender_target_common_chan.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 13:12:08 by cledant           #+#    #+#             */
/*   Updated: 2017/03/28 14:12:54 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

int		srv_has_sender_target_common_chan(t_env *env, const int fd_target,
			const int fd_sender)
{
	size_t		c;

	c = 0;
	while (c < MAX_NB_CHAN)
	{
		if (env->list_fd[fd_target].joined_chan[c] == 1 &&
				env->list_fd[fd_sender].joined_chan[c] == 1)
			return (1);
		c++;
	}
	return (0);
}
