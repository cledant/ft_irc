/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_cmd_join.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 15:58:25 by cledant           #+#    #+#             */
/*   Updated: 2017/04/01 12:04:15 by cledant          ###   ########.fr       */
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
	else if (err == ERR_CHAN_DOES_NOT_EXIST)
		ft_strcat(cmd->cmd, "SMSG That channel does not exist !");
	else
		ft_strcat(cmd->cmd, "SMSG Error !");
	ft_strcat(cmd->cmd, END_PACKET);
	return (1);
}

static inline int		create_msg_to_send(t_cmd *cmd, const int fd_sock,
							const char *user_name, t_userlist *u_list)
{
	cmd->target = TARGET_USER;
	cmd->fd_target = fd_sock;
	cmd->fd_sender = fd_sock;
	ft_strcat(cmd->cmd, BEGIN_PACKET);
	ft_strcat(cmd->cmd, user_name);
	ft_strcat(cmd->cmd, " NAMES ");
	ft_strcat(cmd->cmd, u_list->chan_name);
	ft_strcat(cmd->cmd, " ");
	ft_strcat(cmd->cmd, u_list->user_list);
	ft_strcat(cmd->cmd, END_PACKET);
	return (1);
}

int						srv_cmd_names(t_cmd *cmd, const t_cmd_arg *arg,
							t_env *env, const int fd_sock)
{
	size_t		arg_size;
	t_userlist	u_list;
	char		user_name[MAX_NICK_LEN + 1];

	ft_bzero(&u_list, sizeof(t_userlist));
	arg_size = arg->end - arg->begin - 7;
	if (arg->end == arg->begin + 7 || arg_size == 0 || arg_size == 1 ||
			arg_size > MAX_CHAN_NAME_LEN || *(arg->begin + 7) != '#')
		return (set_error(cmd, fd_sock, ERR_CHAN_NAME));
	ft_bzero(u_list.chan_name, MAX_CHAN_NAME_LEN + 1);
	ft_memcpy(u_list.chan_name, arg->begin + 7, arg_size);
	if (ft_is_str_alphanum(u_list.chan_name + 1) == 0 ||
			srv_is_str_a_cmd(u_list.chan_name + 1) == 1)
		return (set_error(cmd, fd_sock, ERR_CHAN_NAME));
	if ((u_list.chan_id = srv_seek_chan_id(env, u_list.chan_name)) == -1)
		return (set_error(cmd, fd_sock, ERR_CHAN_DOES_NOT_EXIST));
	srv_seek_userlist(env, &u_list);
	ft_bzero(user_name, MAX_NICK_LEN + 1);
	ft_memcpy(user_name, env->list_fd[fd_sock].nick, MAX_NICK_LEN);
	create_msg_to_send(cmd, fd_sock, user_name, &u_list);
	printf("%s : Client ID : %d request a list of user !\n", env->file_name,
		fd_sock);
	return (1);
}
