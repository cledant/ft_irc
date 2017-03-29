/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_cmd_nick.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 21:51:07 by cledant           #+#    #+#             */
/*   Updated: 2017/03/29 02:15:46 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

static int				set_error(t_cmd *cmd, const int fd_sock)
{
//	ft_puts("ERROR");
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
							const char *cmd_str)
{
//	ft_puts("OK");
	cmd->target = ONE_TIME_TO_USER_WITH_COMMON_CHAN;
	cmd->id_chan = -1;
	cmd->fd_target = -1;
	cmd->fd_sender = fd_sock;
	ft_strcat(cmd->cmd, BEGIN_PACKET);
	ft_strcat(cmd->cmd, "WIP");
	ft_strcat(cmd->cmd, cmd_str);
	ft_strcat(cmd->cmd, END_PACKET);
	return (1);
}

int						srv_cmd_nick(t_cmd *cmd, const char *begin,
							const char *end, const int fd_sock)
{
	size_t		arg_size;
	char		*arg;

	if (end == begin + 6 || (arg_size = end - begin - 6) == 0)
		return (set_error(cmd, fd_sock));
	if (arg_size > MAX_MSG_LEN)
		return (set_error(cmd, fd_sock));
	if ((arg = ft_strnew(arg_size)) == NULL)
		return (set_error(cmd, fd_sock));
	ft_memcpy(arg, begin + 6, arg_size);
//	printf("ARG = |%s| %ld\n", arg, arg_size);
	if (ft_is_str_alphanum(arg) == 0)
	{
		free(arg);
		return (set_error(cmd, fd_sock));
	}
	create_msg_to_send(cmd, fd_sock, arg);
	free(arg);
	return (1);
}
