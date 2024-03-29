/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clnt_cmd_connect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 18:32:40 by cledant           #+#    #+#             */
/*   Updated: 2017/05/01 15:44:15 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

static inline void		no_port(char *first_arg, t_clnt_env *env,
							const t_cmd_arg *arg, const char *ptr_first_arg)
{
	ft_memcpy(first_arg, ptr_first_arg + 1, arg->end - ptr_first_arg);
	if (env->state == CONNECTED)
		clnt_disconnect(env);
	if (clnt_connect_server(first_arg, DEFAULT_PORT, env) != ERR_NONE)
	{
		wprintw(env->out, "Couldn't connect to server !\n");
		clnt_disconnect(env);
	}
}

static inline int		check_first_arg(char **ptr_first_arg, t_clnt_env *env,
							const t_cmd_arg *arg)
{
	if ((*ptr_first_arg = ft_strchr(arg->begin, ' ')) == NULL)
	{
		wprintw(env->out, "Not enough arguments for /connect\n");
		return (0);
	}
	if (arg->end - *ptr_first_arg == 0)
	{
		wprintw(env->out, "Not enough arguments for /connect\n");
		return (0);
	}
	return (1);
}

static inline char		*check_separator(const char *ptr_first_arg)
{
	char	*ptr_second_arg;

	if ((ptr_second_arg = ft_strchr(ptr_first_arg + 1, ' ')) != NULL)
		return (ptr_second_arg);
	else if ((ptr_second_arg = ft_strchr(ptr_first_arg + 1, ':')) != NULL)
		return (ptr_second_arg);
	return (NULL);
}

int						clnt_cmd_connect(const t_cmd_arg *arg, t_clnt_env *env)
{
	char	*ptr_first_arg;
	char	*ptr_second_arg;
	char	first_arg[MAX_MSG_LEN + 1];
	char	second_arg[MAX_MSG_LEN + 1];

	if (check_first_arg(&ptr_first_arg, env, arg) == 0)
		return (0);
	ft_bzero(first_arg, MAX_MSG_LEN + 1);
	ft_bzero(second_arg, MAX_MSG_LEN + 1);
	if ((ptr_second_arg = check_separator(ptr_first_arg)) == NULL)
		no_port(first_arg, env, arg, ptr_first_arg);
	else
	{
		ft_memcpy(first_arg, ptr_first_arg + 1,
			ptr_second_arg - ptr_first_arg - 1);
		ft_memcpy(second_arg, ptr_second_arg + 1, arg->end - ptr_second_arg);
		if (env->state == CONNECTED)
			clnt_disconnect(env);
		if (clnt_connect_server(first_arg, second_arg, env) != ERR_NONE)
		{
			wprintw(env->out, "Couldn't connect to server !\n");
			clnt_disconnect(env);
		}
	}
	return (1);
}
