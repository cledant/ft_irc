/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clnt_cmd_leave.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 12:34:18 by cledant           #+#    #+#             */
/*   Updated: 2017/04/20 21:23:51 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

int		clnt_cmd_leave(const t_cmd_arg *arg, t_clnt_env *env)
{
	if (arg->end - arg->begin > MAX_PACKET_SIZE)
	{
		wprintw(env->out, "Message size error !\n");
		return (0);
	}
	if (arg->end - arg->begin == 5)
	{
		ft_strcat(env->cbuff_write->enqueue_buff, ":PART ");
		ft_strcat(env->cbuff_write->enqueue_buff, env->last_chan);
		ft_strcat(env->cbuff_write->enqueue_buff, END_PACKET);
		cbuff_enqueue(env->cbuff_write, ft_strlen(
			env->cbuff_write->enqueue_buff));
		return (1);
	}
	if (arg->end - arg->begin < 7)
	{
		wprintw(env->out, "Invalid /leave command !\n");
		return (0);
	}
	ft_strcat(env->cbuff_write->enqueue_buff, ":PART ");
	ft_strcat(env->cbuff_write->enqueue_buff, arg->begin + 7);
	ft_strcat(env->cbuff_write->enqueue_buff, END_PACKET);
	cbuff_enqueue(env->cbuff_write, ft_strlen(env->cbuff_write->enqueue_buff));
	return (1);
}
