/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clnt_check_other_cmd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 16:05:58 by cledant           #+#    #+#             */
/*   Updated: 2017/04/20 16:20:51 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

int		clnt_check_other_cmd(const char *cmd_part, const t_cmd_arg *arg,
			t_disp_cmd *cmd, const char *begin)
{
	if (ft_strcmp(cmd_part, "NICK") == 0)
		return (clnt_parse_nick(arg, cmd, begin));
/*	else if (ft_strcmp(cmd_part, "JOIN") == 0)
		return (clnt_parse_join(arg, cmd, begin));
	else if (ft_strcmp(cmd_part, "PART") == 0)
		return (clnt_parse_part(arg, cmd, begin));
	else if (ft_strcmp(cmd_part, "QUIT") == 0)
		return (clnt_parse_quit(arg, cmd, begin));
	else if (ft_strcmp(cmd_part, "PRIVMSG") == 0)
		return (clnt_parse_privmsg(arg, cmd, begin));
	else if (ft_strcmp(cmd_part, "NAMES") == 0)
		return (clnt_parse_names(arg, cmd, begin));*/
	return (1);
}
