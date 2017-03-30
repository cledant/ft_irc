/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_is_str_a_cmd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 13:20:59 by cledant           #+#    #+#             */
/*   Updated: 2017/03/30 13:34:14 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

int						srv_is_str_a_cmd(const char *cmd_str)
{
	if (ft_strcmp(cmd_str, "NICK") == 0)
		return (1);
	else if (ft_strcmp(cmd_str, "JOIN") == 0)
		return (1);
	else if (ft_strcmp(cmd_str, "PART") == 0)
		return (1);
	else if (ft_strcmp(cmd_str, "NAMES") == 0)
		return (1);
	else if (ft_strcmp(cmd_str, "PRIVMSG") == 0)
		return (1);
	else if (ft_strcmp(cmd_str, "WELCOME") == 0)
		return (1);
	else if (ft_strcmp(cmd_str, "SMSG") == 0)
		return (1);
	else if (ft_strcmp(cmd_str, "QUIT") == 0)
		return (1);
	return (0);
}
