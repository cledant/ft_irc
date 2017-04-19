/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clnt_cmd_disconnect.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 18:20:26 by cledant           #+#    #+#             */
/*   Updated: 2017/04/19 15:17:58 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

int		clnt_cmd_disconnect(const t_cmd_arg *arg, t_clnt_env *env)
{
	if (arg->end - arg->begin == 10)
	{
		if (env->state == CONNECTED)
			clnt_disconnect(env);
		else
			wprintw(env->out, "\nAlready disconnected from server!");
	}
	else
		wprintw(env->out, "\nInvalid use of /disconnect");
	return (1);
}
