/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clnt_read_cmd_server.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 11:17:26 by cledant           #+#    #+#             */
/*   Updated: 2017/04/20 18:57:02 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

static inline int		error_advance_head(t_clnt_env *env, const size_t size)
{
	cbuff_move_forward_read_head(env->cbuff_read, size);
	return (0);
}

static inline int		disp_cmd(t_disp_cmd *cmd, t_clnt_env *env)
{
	if (cmd->function == NICK)
		return (clnt_disp_nick(cmd, env));
	else if (cmd->function == JOIN)
		return (clnt_disp_join(cmd, env));
	else if (cmd->function == PART)
		return (clnt_disp_part(cmd, env));
	else if (cmd->function == QUIT)
		return (clnt_disp_quit(cmd, env));
	else if (cmd->function == PRIVMSG)
		return (clnt_disp_privmsg(cmd, env));
/*	else if (cmd->function == NAMES)
		return (clnt_disp_names(cmd, arg, env, fd_sock));*/
	else if (cmd->function == SMSG)
		return (clnt_disp_smsg(cmd, env));
	else if (cmd->function == WELCOME)
		return (clnt_disp_welcome(cmd, env));
	return (0);
}

static inline int		get_cmd(const t_cmd_arg *arg, t_clnt_env *env,
							t_disp_cmd *cmd)
{
	size_t	size;
	char	*space;
	char	cmd_str[MAX_PACKET_SIZE + 1];

	size = arg->end - arg->begin - 1;
	if (size == 0 || size > MAX_PACKET_SIZE || ft_isspace(*(arg->begin + 1))
			== 1)
		return (0);
	if ((space = ft_strnstr(arg->begin, " ", size)) == NULL)
		return (0);
	ft_bzero(cmd_str, MAX_PACKET_SIZE + 1);
	ft_memcpy(cmd_str, arg->begin + 1, space - 1 - arg->begin);
	if (clnt_disp_first_cmd_check(cmd_str, cmd, arg) == 0)
		return (0);
	disp_cmd(cmd, env);
	return (1);
}

int						clnt_read_cmd_server(t_clnt_env *env, t_disp_cmd *cmd)
{
	t_cmd_arg		arg;

	cbuff_dequeue_till_head_no_change(env->cbuff_read);
	if ((arg.begin = ft_strnstr(env->cbuff_read->dequeue_buff, BEGIN_PACKET,
			CBUFF_SIZE)) == NULL)
		return (0);
	if ((arg.end = ft_strnstr(env->cbuff_read->dequeue_buff, END_PACKET,
			CBUFF_SIZE)) == NULL)
		return (0);
	if (arg.begin > arg.end)
	{
		if ((arg.end = ft_strnstr(arg.begin, END_PACKET, CBUFF_SIZE)) == NULL)
			return (error_advance_head(env, arg.begin -
				env->cbuff_read->dequeue_buff));
	}
	if (get_cmd(&arg, env, cmd) == 0)
	{
		return (error_advance_head(env, arg.end - env->cbuff_read->dequeue_buff
			+ ft_strlen(END_PACKET) - 1));
	}
	cbuff_move_forward_read_head(env->cbuff_read, arg.end -
		env->cbuff_read->dequeue_buff + ft_strlen(END_PACKET) - 1);
	return (1);
}
