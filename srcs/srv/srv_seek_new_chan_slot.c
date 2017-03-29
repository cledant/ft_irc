/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_seek_new_chan_slot.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 18:07:29 by cledant           #+#    #+#             */
/*   Updated: 2017/03/29 18:16:03 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

int		srv_seek_new_chan_slot(t_env *env)
{
	int		c;

	c = 0;
	while (c < MAX_NB_CHAN)
	{
		if (env->list_chan[c].state == CHAN_FREE)
			return (c);
		c++;
	}
	return (-1);
}
