/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clnt_cmd_part.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 11:37:00 by cledant           #+#    #+#             */
/*   Updated: 2017/04/19 11:54:08 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

int		clnt_cmd_part(const t_cmd_arg *arg, t_clnt_env *env)
{
	if (arg->end - arg->begin > MAX_PACKET_SIZE)
	{
		wprintw(env->out, "\nMessage size error !");
		return (0);
	}
	if (arg->end - arg->begin < 6)
	{
		wprintw(env->out, "\nInvalid /nick command !");
		return (0);
	}
	ft_strcat(env->cbuff_write->enqueue_buff, ":PART ");
	ft_strcat(env->cbuff_write->enqueue_buff, arg->begin + 6);
	cbuff_enqueue(env->cbuff_write, ft_strlen(env->cbuff_write->enqueue_buff));
	return (1);
}
