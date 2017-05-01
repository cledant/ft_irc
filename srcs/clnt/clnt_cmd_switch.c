/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clnt_cmd_switch.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 13:21:09 by cledant           #+#    #+#             */
/*   Updated: 2017/05/01 13:40:00 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

static inline int		checks(const t_cmd_arg *arg, t_clnt_env *env)
{
	if (arg->end - arg->begin > MAX_PACKET_SIZE)
	{
		wprintw(env->out, "Message size error !\n");
		return (0);
	}
	if (arg->end - arg->begin < 8)
	{
		wprintw(env->out, "Invalid /switch command !\n");
		return (0);
	}
	if (*(arg->begin + 8) != '#')
	{
		wprintw(env->out, "Not a channel !\n");
		return (0);
	}
	if (arg->end - 1 - arg->begin + 8 > MAX_CHAN_NAME_LEN)
	{
		wprintw(env->out, "Invalid channel !\n");
		return (0);
	}
	return (1);
}

int						clnt_cmd_switch(const t_cmd_arg *arg, t_clnt_env *env)
{
	if (checks(arg, env) == 0)
		return (0);
	ft_bzero(env->last_chan, MAX_CHAN_NAME_LEN + 1);
	ft_memcpy(env->last_chan, arg->begin + 8, arg->end - 1 - arg->begin + 8);
	wprintw(env->out, "Switched to channel : %s !\n", env->last_chan);
	return (1);
}
