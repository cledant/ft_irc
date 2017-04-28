/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_cmd_nick.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 21:51:07 by cledant           #+#    #+#             */
/*   Updated: 2017/04/28 11:26:02 by cledant          ###   ########.fr       */
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

int						srv_cmd_nick(t_cmd *cmd, const t_cmd_arg *arg,
							t_env *env, const int fd_sock)
{
	size_t		arg_size;
	char		old_name[MAX_NICK_LEN + 1];
	char		new_name[MAX_NICK_LEN + 1];

	arg_size = arg->end - arg->begin - 6;
	if (arg->end == arg->begin + 6 || arg_size == 0 || arg_size > MAX_NICK_LEN)
		return (set_error(cmd, fd_sock));
	ft_bzero(new_name, MAX_NICK_LEN + 1);
	ft_memcpy(new_name, arg->begin + 6, arg_size);
	if (srv_is_nick_valid(new_name) == 0 || srv_is_str_a_cmd(new_name) == 1)
		return (set_error(cmd, fd_sock));
	ft_bzero(old_name, MAX_NICK_LEN + 1);
	ft_memcpy(old_name, env->list_fd[fd_sock].nick, MAX_NICK_LEN);
	ft_memcpy(env->list_fd[fd_sock].nick, new_name, MAX_NICK_LEN);
	create_msg_to_send(cmd, fd_sock, old_name, new_name);
	printf("%s : Client ID : %d changed nick !\n", env->file_name, fd_sock);
	return (1);
}
