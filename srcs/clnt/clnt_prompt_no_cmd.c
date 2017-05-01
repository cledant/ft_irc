/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clnt_prompt_no_cmd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 13:51:00 by cledant           #+#    #+#             */
/*   Updated: 2017/05/01 14:23:38 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

int		clnt_prompt_no_cmd(t_clnt_env *env)
{
	t_cmd_arg	arg;
	char		cpy_buff[MAX_MSG_LEN + 1];

	if (env->state != CONNECTED)
	{
		wprintw(env->out, "You are not connected to a server !\n");
		return (0);
	}
	if ((arg.end = ft_strnstr(env->buff, CLNT_END_CMD, MAX_MSG_LEN)) == NULL)
		return (0);
	arg.begin = env->buff;
	if (arg.end - arg.begin > MAX_MSG_LEN)
		return (0);
	ft_bzero(cpy_buff, MAX_MSG_LEN + 1);
	ft_memcpy(cpy_buff, arg.begin, arg.end - arg.begin);
	ft_strcat(env->cbuff_write->enqueue_buff, ":PRIVMSG ");
	ft_strcat(env->cbuff_write->enqueue_buff, env->last_chan);
	ft_strcat(env->cbuff_write->enqueue_buff, " ");
	ft_strcat(env->cbuff_write->enqueue_buff, cpy_buff);
	ft_strcat(env->cbuff_write->enqueue_buff, END_PACKET);
	cbuff_enqueue(env->cbuff_write, ft_strlen(env->cbuff_write->enqueue_buff));
	return (1);
}
