/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_is_cmd_valid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 21:01:26 by cledant           #+#    #+#             */
/*   Updated: 2017/03/27 21:43:03 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

static inline int		set_enum(t_cmd *cmd, const t_func func)
{
	cmd->function = func;
	return (1);
}

int						srv_is_cmd_valid(const char *cmd, t_cmd *cmd)
{
	if (ft_strcmp(cmd, "NICK") == 0)
		return (set_enum(cmd, NICK));
	else if (ft_strcmp(cmd, "JOIN") == 0)
		return (set_enum(cmd, JOIN));
	else if (ft_strcmp(cmd, "PART") == 0)
		return (set_enum(cmd, PART));
	else if (ft_strcmp(cmd, "NAMES") == 0)
		return (set_enum(cmd, NAMES));
	else if (ft_strcmp(cmd, "PRIVMSG") == 0)
		return (set_enum(cmd, PRIVMSG));
	else if (ft_strcmp(cmd, "WELCOME") == 0)
		return (set_enum(cmd, WELCOME));
	else if (ft_strcmp(cmd, "SMSG") == 0)
		return (set_enum(cmd, SMSG));
	ft_puts("Invalid command send !");
	return (0);
}
