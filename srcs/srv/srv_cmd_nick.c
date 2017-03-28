/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_cmd_nick.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 21:51:07 by cledant           #+#    #+#             */
/*   Updated: 2017/03/28 11:59:55 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

static int				set_error(t_cmd *cmd)
{
	cmd->function = SMSG;
	cmd->target = TARGET_USER;
	cmd->id_chan = -1;
	cmd->fd_target = fd_sock;
	cmd->fd_sender = fd_sock;
	ft_strcat(cmd->cmd, ":SMSG Invalid Nick !");
}

static inline int		create_msg_to_send(t_cmd *cmd, const char *cmd)
{
	ft_strcat(cmd->cmd, ":NICK ");
	ft_strcat(cmd->cmd, cmd);
}

int						srv_cmd_nick(t_cmd *cmd, char *begin, char *end,
							const int fd_sock)
{
	size_t		arg_size;
	char		*arg;

	if (end == begin + 6 || (arg_size = end - begin + 6) == 0)
		return (set_error(cmd));
	if (arg_size > MAX_MSG_LEN)
		return (set_error(cmd));
	if ((arg = ft_strnew(arg_size)) == NULL)
		return (set_error(cmd));
	ft_memcpy(arg, begin + 6, arg_size);
	if (ft_is_str_alnum(arg) == 0)
	{
		free(arg);
		return (set_error(cmd));
	}
	cmd->target = ONE_TIME_TO_USER_WITH_COMMON_CHAN;
	cmd->id_chan = -1;
	cmd->fd_target = -1;
	cmd->fd_sender = fd_sock;
	create_msg_to_send(cmd, arg);
	free(arg);
	return (1);
}
