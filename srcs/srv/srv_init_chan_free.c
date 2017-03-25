/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_init_chan_free.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 14:07:39 by cledant           #+#    #+#             */
/*   Updated: 2017/03/25 14:11:53 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

void		srv_init_chan_free(t_chan *chan)
{
	chan->state = CHAN_FREE;
	ft_bzero(chan->name, MAX_CHAN_NAME_LEN + 1);
	chan->nb_user = 0;
}
