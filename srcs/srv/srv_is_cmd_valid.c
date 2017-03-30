/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_is_cmd_valid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 21:01:26 by cledant           #+#    #+#             */
/*   Updated: 2017/03/30 14:35:19 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

static inline int		set_enum(t_cmd *cmd, const t_func func)
{
	cmd->function = func;
	return (1);
}

int						srv_is_cmd_valid(const char *cmd_str, t_cmd *cmd)
{
	if (ft_strcmp(cmd_str, "NICK") == 0)
		return (set_enum(cmd, NICK));
	else if (ft_strcmp(cmd_str, "JOIN") == 0)
		return (set_enum(cmd, JOIN));
	else if (ft_strcmp(cmd_str, "PART") == 0)
		return (set_enum(cmd, PART));
	else if (ft_strcmp(cmd_str, "NAMES") == 0)
		return (set_enum(cmd, NAMES));
	else if (ft_strcmp(cmd_str, "PRIVMSG") == 0)
		return (set_enum(cmd, PRIVMSG));
	else if (ft_strcmp(cmd_str, "WELCOME") == 0)
		return (set_enum(cmd, WELCOME));
	else if (ft_strcmp(cmd_str, "SMSG") == 0)
		return (set_enum(cmd, SMSG));
	else if (ft_strcmp(cmd_str, "QUIT") == 0)
		return (set_enum(cmd, QUIT));
	ft_puts("Invalid command received !");
	return (0);
}
