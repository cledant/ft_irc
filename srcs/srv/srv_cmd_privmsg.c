/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_cmd_privmsg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 16:54:29 by cledant           #+#    #+#             */
/*   Updated: 2017/03/30 23:33:00 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

static int				set_error(t_cmd *cmd, const int fd_sock)
{
	cmd->function = SMSG;
	cmd->target = TARGET_SENDER;
	cmd->id_chan = -1;
	cmd->fd_target = -1;
	cmd->fd_sender = fd_sock;
	ft_strcat(cmd->cmd, BEGIN_PACKET);
	ft_strcat(cmd->cmd, "SMSG Invalid message !");
	ft_strcat(cmd->cmd, END_PACKET);
	return (1);
}

static inline int		create_msg_to_send(t_cmd *cmd, const int fd_sock,
							const t_privmsg *parse, t_env *env)
{
	if (parse->type == IS_CHAN)
	{
		cmd->target = TARGET_CHAN;
		if ((cmd->id_chan = srv_seek_chan_id(env, parse->chan_name)) == -1)
			return (-1);	
		cmd->fd_target = -1;
		cmd->fd_sender = fd_sock;
	}
	else
	{
		cmd->target = TARGET_USER;
		if ((cmd->fd_target = srv_seek_user_fd(env, parse->user_name)) == -1)
			return (-1);	
		cmd->id_chan = -1;
		cmd->fd_sender = fd_sock;
	}
	ft_strcat(cmd->cmd, BEGIN_PACKET);
	ft_strcat(cmd->cmd, env->list_fd[fd_sock].nick);
	ft_strcat(cmd->cmd, " PRIVMSG ");
	(parse->type == IS_CHAN) ? ft_strcat(cmd->cmd, parse->chan_name) :
		ft_strcat(cmd->cmd, parse->user_name);
	ft_strcat(cmd->cmd, " ");
	ft_strcat(cmd->cmd, parse->msg_content);
	ft_strcat(cmd->cmd, END_PACKET);
	return (1);
}

static inline int		check_privmsg_msg(t_privmsg *parse)
{
	if ((parse->second_arg_size = parse->buffer_size - parse->first_arg_size)
			== 0)
		return (-1);
	if (parse->second_arg_size > MAX_MSG_LEN)
		return (-1);
	ft_memcpy(parse->msg_content, parse->first_arg.end + 1,
		parse->second_arg_size);
	return (1);
}

static inline int		check_privmsg_type(t_privmsg *parse)
{
	parse->first_arg.begin = parse->buffer;
	if ((parse->first_arg.end = ft_strnstr(parse->buffer, " ",
			MAX_PACKET_SIZE)) == NULL)
		return (-1);
	parse->first_arg_size = parse->first_arg.end - parse->first_arg.begin;
	if (parse->first_arg_size == 0)
		return (-1);
	if (*(parse->buffer) == '#')
	{
		parse->type = IS_CHAN;
		if (parse->first_arg_size > MAX_CHAN_NAME_LEN)
			return (-1);
		ft_memcpy(parse->chan_name, parse->buffer, parse->first_arg_size);
	}
	else
	{
		parse->type = IS_USER;
		if (parse->first_arg_size > MAX_NICK_LEN)
			return (-1);
		ft_memcpy(parse->user_name, parse->buffer, parse->first_arg_size);
	}
	return (1);
}

int						srv_cmd_privmsg(t_cmd *cmd, const t_cmd_arg *arg,
							t_env *env, const int fd_sock)
{
	size_t		arg_size;
	t_privmsg	parse;

	arg_size = arg->end - arg->begin - 9;
	if (arg->end == arg->begin + 9 || arg_size == 0 ||
			arg_size > MAX_MSG_LEN + MAX_CHAN_NAME_LEN + 1)
		return (set_error(cmd, fd_sock));
	ft_bzero(&parse, sizeof(t_privmsg));
	ft_memcpy(parse.buffer, arg->begin + 9, arg_size);
	parse.buffer_size = arg_size;
	if (check_privmsg_type(&parse) == -1)
		return (set_error(cmd, fd_sock));
	if (check_privmsg_msg(&parse) == -1)
		return (set_error(cmd, fd_sock));
	if (create_msg_to_send(cmd, fd_sock, &parse, env) == -1)
		return (set_error(cmd, fd_sock));
	if (parse.type == IS_CHAN &&
			env->list_fd[fd_sock].joined_chan[cmd->id_chan] == NOT_IN_CHAN)
		return (set_error(cmd, fd_sock));
	printf("%s : Client ID : %d sent a message !\n", env->file_name, fd_sock);
	return (1);
}
