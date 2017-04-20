/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clnt_disp_first_cmd_check.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 11:44:31 by cledant           #+#    #+#             */
/*   Updated: 2017/04/20 13:19:59 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

int		clnt_disp_first_cmd_check(const char *cmd_str, t_disp_cmd *cmd,
			const t_cmd_arg *arg)
{
	size_t		len;

	if (ft_strcmp(cmd_str, "SMSG") == 0)
		return (clnt_parse_smsg(arg, cmd));
	if ((len = ft_strlen(cmd_str)) > MAX_NICK_LEN)
		return (0);
	if (len == 0)
		return (0);
	ft_memcpy(cmd->nick, cmd_str, len);
	if (clnt_disp_second_cmd_check(cmd, arg) == 0)
		return (0);
	return (1);
}
