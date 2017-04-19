/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clnt_cmd_join.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 11:32:11 by cledant           #+#    #+#             */
/*   Updated: 2017/04/19 14:59:27 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

int		clnt_cmd_join(const t_cmd_arg *arg, t_clnt_env *env)
{
	if (arg->end - arg->begin > MAX_PACKET_SIZE)
	{
		wprintw(env->out, "\nMessage size error !");
		return (0);
	}
	if (arg->end - arg->begin < 6)
	{
		wprintw(env->out, "\nInvalid /join command !");
		return (0);
	}
	ft_strcat(env->cbuff_write->enqueue_buff, ":JOIN ");
	ft_strcat(env->cbuff_write->enqueue_buff, arg->begin + 6);
	ft_strcat(env->cbuff_write->enqueue_buff, END_PACKET);
	ft_bzero(env->last_chan, MAX_CHAN_NAME_LEN + 1);
	ft_strncpy(env->last_chan, arg->begin + 6, MAX_CHAN_NAME_LEN);
	cbuff_enqueue(env->cbuff_write, ft_strlen(env->cbuff_write->enqueue_buff));
	return (1);
}
