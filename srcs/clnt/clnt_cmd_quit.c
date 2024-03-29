/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clnt_cmd_quit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 12:03:02 by cledant           #+#    #+#             */
/*   Updated: 2017/04/20 21:25:07 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

int		clnt_cmd_quit(const t_cmd_arg *arg, t_clnt_env *env)
{
	if (arg->end - arg->begin > MAX_PACKET_SIZE)
	{
		wprintw(env->out, "Message size error !\n");
		return (0);
	}
	if (arg->end - arg->begin < 6)
	{
		wprintw(env->out, "Invalid /quit command !\n");
		return (0);
	}
	ft_strcat(env->cbuff_write->enqueue_buff, ":QUIT ");
	ft_strcat(env->cbuff_write->enqueue_buff, arg->begin + 6);
	ft_strcat(env->cbuff_write->enqueue_buff, END_PACKET);
	cbuff_enqueue(env->cbuff_write, ft_strlen(env->cbuff_write->enqueue_buff));
	return (1);
}
