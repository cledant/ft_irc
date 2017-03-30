/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_cmd_privmsg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 16:54:29 by cledant           #+#    #+#             */
/*   Updated: 2017/03/30 18:19:37 by cledant          ###   ########.fr       */
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
	ft_strcat(cmd->cmd, "SMSG Invalid Nick !");
	ft_strcat(cmd->cmd, END_PACKET);
	return (1);
}

static inline int		create_msg_to_send(t_cmd *cmd, const int fd_sock,
							const char *old_name, const char *new_name)
{
	cmd->target = ONE_TIME_TO_USER_WITH_COMMON_CHAN;
	cmd->id_chan = -1;
	cmd->fd_target = -1;
	cmd->fd_sender = fd_sock;
	ft_strcat(cmd->cmd, BEGIN_PACKET);
	ft_strcat(cmd->cmd, new_name);
	ft_strcat(cmd->cmd, " NICK ");
	ft_strcat(cmd->cmd, old_name);
	ft_strcat(cmd->cmd, END_PACKET);
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
	ft_bzero(parse, sizeof(t_privmsg));
	ft_memcpy(parse.buffer, arg->begin + 9, arg_size);
	if (check_privmsg_type(&parse) == -1)
		return (set_error(cmd, fd_sock));
	create_msg_from_parse(cmd, parse);
	create_msg_to_send(cmd, fd_sock, old_name, new_name);
	printf("%s : Client ID : %d sent a message !\n", env->file_name, fd_sock);
	return (1);
}
