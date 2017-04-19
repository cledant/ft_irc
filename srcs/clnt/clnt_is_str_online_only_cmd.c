/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clnt_is_str_online_only_cmd.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 20:14:06 by cledant           #+#    #+#             */
/*   Updated: 2017/04/19 20:14:09 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

int			clnt_is_str_online_only_cmd(const char *cmd_str)
{
	if (ft_strcmp(cmd_str, "nick") == 0)
		return (1);
	else if (ft_strcmp(cmd_str, "join") == 0)
		return (1);
	else if (ft_strcmp(cmd_str, "leave") == 0)
		return (1);
	else if (ft_strcmp(cmd_str, "who") == 0)
		return (1);
	else if (ft_strcmp(cmd_str, "msg") == 0)
		return (1);
	else if (ft_strcmp(cmd_str, "quit") == 0)
		return (1);
	return (0);
}
