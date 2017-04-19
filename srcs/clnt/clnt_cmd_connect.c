/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clnt_cmd_connect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 18:32:40 by cledant           #+#    #+#             */
/*   Updated: 2017/04/19 15:17:27 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

int		clnt_cmd_connect(const t_cmd_arg *arg, t_clnt_env *env)
{
	char	*ptr_first_arg;
	char	*ptr_second_arg;
	char	first_arg[MAX_MSG_LEN + 1];
	char	second_arg[MAX_MSG_LEN + 1];

	if ((ptr_first_arg = ft_strchr(arg->begin, ' ')) == NULL)
	{
		wprintw(env->out, "\nNot enough arguments for /connect");
		return (0);
	}
	ft_bzero(first_arg, MAX_MSG_LEN + 1);
	ft_bzero(second_arg, MAX_MSG_LEN + 1);
	if ((ptr_second_arg = ft_strchr(ptr_first_arg + 1, ' ')) == NULL)
	{
		ft_memcpy(first_arg, ptr_first_arg + 1, arg->end - ptr_first_arg);
		if (env->state == CONNECTED)
			clnt_disconnect(env);
		if (clnt_connect_server(first_arg, DEFAULT_PORT, env) != ERR_NONE)
		{
			wprintw(env->out, "\nCouldn't connect to server !");
			clnt_disconnect(env);
		}
	}
	else
	{
		ft_memcpy(first_arg, ptr_first_arg + 1, ptr_second_arg - ptr_first_arg - 1);
		ft_memcpy(second_arg, ptr_second_arg + 1, arg->end - ptr_second_arg);
		if (env->state == CONNECTED)
			clnt_disconnect(env);
		if (clnt_connect_server(first_arg, second_arg, env) != ERR_NONE)
		{
			wprintw(env->out, "\nCouldn't connect to server !");
			clnt_disconnect(env);
		}
	}
	return (1);
}
