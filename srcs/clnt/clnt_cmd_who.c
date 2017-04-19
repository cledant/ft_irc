/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clnt_cmd_who.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 12:13:13 by cledant           #+#    #+#             */
/*   Updated: 2017/04/19 13:18:00 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

int		clnt_cmd_who(const t_cmd_arg *arg, t_clnt_env *env)
{
	if (arg->end - arg->begin > MAX_PACKET_SIZE)
	{
		wprintw(env->out, "\nMessage size error !");
		return (0);
	}
	if (arg->end - arg->begin == 4)
	{
		ft_strcat(env->cbuff_write->enqueue_buff, ":NAMES ");
		ft_strcat(env->cbuff_write->enqueue_buff, env->last_chan);
		ft_strcat(env->cbuff_write->enqueue_buff, END_PACKET);
		return (1);
	}
	if (arg->end - arg->begin < 5)
	{
		wprintw(env->out, "\nInvalid /who command !");
		return (0);
	}
	ft_strcat(env->cbuff_write->enqueue_buff, ":NAMES ");
	ft_strcat(env->cbuff_write->enqueue_buff, arg->begin + 5);
	cbuff_enqueue(env->cbuff_write, ft_strlen(env->cbuff_write->enqueue_buff));
	return (1);
}
