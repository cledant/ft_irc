/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clnt_interpret_prompt_cmd.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 17:01:34 by cledant           #+#    #+#             */
/*   Updated: 2017/04/18 18:41:54 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

static inline int		finish_cmd(const char *cmd_str, const t_cmd_arg *arg,
							t_clnt_env *env)
{
	if (ft_strcmp(cmd_str, "connect") == 0)
		return (clnt_cmd_connect(arg, env));
	else if (ft_strcmp(cmd_str, "disconnect") == 0)
		return (clnt_cmd_disconnect(arg, env));
/*	else if (ft_strcmp(cmd_str, "nick") == 0)
		return (clnt_cmd_nick(arg, env));
	else if (ft_strcmp(cmd_str, "join") == 0)
		return (clnt_cmd_join(arg, env));
	else if (ft_strcmp(cmd_str, "leave") == 0)
		return (clnt_cmd_part(cmd_str, arg, env));
	else if (ft_strcmp(cmd_str, "quit") == 0)
		return (clnt_cmd_quit(arg, env));
	else if (ft_strcmp(cmd_str, "msg") == 0)
		return (clnt_cmd_privmsg(arg, env));
	else if (ft_strcmp(cmd_str, "who") == 0)
		return (srv_cmd_names(arg, env));*/
	wprintw(env->out, "\nUnknown command !");
	return (0);
}

static inline int		get_cmd(const t_cmd_arg *arg, t_clnt_env *env)
{
	size_t	size;
	char	*space;
	char	cmd_str[MAX_PACKET_SIZE + 1];

	size = arg->end - arg->begin - 1;
	if (size == 0 || size > MAX_MSG_LEN || ft_isspace(*(arg->begin + 1))
			== 1)
		return (0);
	ft_bzero(cmd_str, MAX_PACKET_SIZE + 1);
	if ((space = ft_strnstr(arg->begin, " ", size)) == NULL)
		ft_memcpy(cmd_str, arg->begin + 1, arg->end - 1 - arg->begin);
	else
		ft_memcpy(cmd_str, arg->begin + 1, space - 1 - arg->begin);
	finish_cmd(cmd_str, arg, env);
	return (1);
}

int						clnt_interpret_prompt_cmd(t_clnt_env *env)
{
	t_cmd_arg		arg;

	if ((arg.begin = ft_strnstr(env->buff, CLNT_BEGIN_CMD, MAX_MSG_LEN))
			== NULL)
		return (0);
	if ((arg.end = ft_strnstr(env->buff, CLNT_END_CMD, MAX_MSG_LEN)) == NULL)
		return (0);
	if (arg.begin > arg.end || arg.begin != &(env->buff[0]))
		return (0);
	if (get_cmd(&arg, env) == 0)
		return (0);
	return (1);
}
