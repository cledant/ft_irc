/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_cmd_nick.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 21:51:07 by cledant           #+#    #+#             */
/*   Updated: 2017/03/27 22:22:09 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

int		srv_cmd_nick(t_cmd *cmd, char *begin, char *end)
{
	size_t		arg_size;
	char		*arg;

	if (*(begin + 5) != ' ')
		return (set_error(cmd));
	if ((arg_size = end - begin + 6) == 0)
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
	cmd->target = ALL_CHAN_WITH_CUR_USER;
	cmd->id_chan = -1;
	cmd->fd_target = -1;
	create_msg_to_send(cmd, arg);
	return (1);
}
