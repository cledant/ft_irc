/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clnt_check_other_cmd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 16:05:58 by cledant           #+#    #+#             */
/*   Updated: 2017/04/20 16:55:10 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

int		clnt_check_other_cmd(const char *cmd_part, const t_cmd_arg *arg,
			t_disp_cmd *cmd, const char *begin)
{
	if (ft_strcmp(cmd_part, "NICK") == 0)
		return (clnt_parse_nick_join_part_quit(arg, cmd, begin, NICK));
	else if (ft_strcmp(cmd_part, "JOIN") == 0)
		return (clnt_parse_nick_join_part_quit(arg, cmd, begin, JOIN));
	else if (ft_strcmp(cmd_part, "PART") == 0)
		return (clnt_parse_nick_join_part_quit(arg, cmd, begin, PART));
	else if (ft_strcmp(cmd_part, "QUIT") == 0)
		return (clnt_parse_nick_join_part_quit(arg, cmd, begin, QUIT));
/*	else if (ft_strcmp(cmd_part, "PRIVMSG") == 0)
		return (clnt_parse_privmsg(arg, cmd, begin));
	else if (ft_strcmp(cmd_part, "NAMES") == 0)
		return (clnt_parse_names(arg, cmd, begin));*/
	return (1);
}
