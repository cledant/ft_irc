/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_seek_chan_id.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 17:58:08 by cledant           #+#    #+#             */
/*   Updated: 2017/03/29 18:37:32 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

int		srv_seek_chan_id(t_env *env, const char *chan_name)
{
	int		c;

	c = 0;
	while (c < MAX_NB_CHAN)
	{
		if (ft_strcmp(chan_name, env->list_chan[c].name) == 0)
			return (c);
		c++;
	}
	return (-1);
}
