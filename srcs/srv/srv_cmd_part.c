/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_cmd_join.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 15:58:25 by cledant           #+#    #+#             */
/*   Updated: 2017/03/30 13:01:13 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

static int				set_error(t_cmd *cmd, const int fd_sock,
							const t_err err)
{
	cmd->function = SMSG;
	cmd->target = TARGET_SENDER;
	cmd->id_chan = -1;
	cmd->fd_target = -1;
	cmd->fd_sender = fd_sock;
	ft_strcat(cmd->cmd, BEGIN_PACKET);
	if (err == ERR_CHAN_NAME)
		ft_strcat(cmd->cmd, "SMSG Invalid channel name !");
	else if (err == ERR_USER_NOT_IN_CHAN)
		ft_strcat(cmd->cmd, "SMSG You are not in that channel !");
	else
		ft_strcat(cmd->cmd, "SMSG Channel does not exist !");
	ft_strcat(cmd->cmd, END_PACKET);
	return (1);
}

static inline int		create_msg_to_send(t_cmd *cmd, const int fd_sock,
							const char *chan_name, const char *user_name)
{
	cmd->target = TARGET_CHAN_AND_SENDER;
	cmd->fd_target = -1;
	cmd->fd_sender = fd_sock;
	ft_strcat(cmd->cmd, BEGIN_PACKET);
	ft_strcat(cmd->cmd, user_name);
	ft_strcat(cmd->cmd, " PART ");
	ft_strcat(cmd->cmd, chan_name);
	ft_strcat(cmd->cmd, END_PACKET);
	return (1);
}

int						srv_cmd_part(t_cmd *cmd, const t_cmd_arg *arg,
							t_env *env, const int fd_sock)
{
	size_t		arg_size;
	char		chan_name[MAX_CHAN_NAME_LEN + 1];
	char		user_name[MAX_NICK_LEN + 1];

	arg_size = arg->end - arg->begin - 6;
	if (arg->end == arg->begin + 6 || arg_size == 0 || arg_size == 1 ||
			arg_size > MAX_CHAN_NAME_LEN || *(arg->begin + 6) != '#')
		return (set_error(cmd, fd_sock, ERR_CHAN_NAME));
	ft_bzero(chan_name, MAX_CHAN_NAME_LEN + 1);
	ft_memcpy(chan_name, arg->begin + 6, arg_size);
	if (ft_is_str_alphanum(chan_name + 1) == 0 ||
			srv_is_str_a_cmd(chan_name + 1) == 1)
		return (set_error(cmd, fd_sock, ERR_CHAN_NAME));
	if ((cmd->id_chan = srv_part_user_to_channel(env, fd_sock, chan_name))
			== -1)
		return (set_error(cmd, fd_sock, ERR_CHAN_DOES_NOT_EXIST));
	if (cmd->id_chan == -2)
		return (set_error(cmd, fd_sock, ERR_USER_NOT_IN_CHAN));
	ft_bzero(user_name, MAX_NICK_LEN + 1);
	ft_memcpy(user_name, env->list_fd[fd_sock].nick, MAX_NICK_LEN);
	create_msg_to_send(cmd, fd_sock, chan_name, user_name);
	printf("%s : Client ID : %d left a channel !\n", env->file_name, fd_sock);
	return (1);
}
