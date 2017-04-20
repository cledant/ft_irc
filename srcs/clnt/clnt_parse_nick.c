/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clnt_parse_nick.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 16:33:43 by cledant           #+#    #+#             */
/*   Updated: 2017/04/20 16:48:31 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

int		clnt_parse_nick(const t_cmd_arg *arg, t_disp_cmd *cmd,
			const char *begin)
{
	size_t	len;

	if ((len = arg->end - begin - 1) == 0)
		return (0);
	if (len > MAX_PACKET_SIZE)
		return (0);
	cmd->function = NICK;
	ft_memcpy(cmd->msg, begin + 1, len);
	return (1);
}
