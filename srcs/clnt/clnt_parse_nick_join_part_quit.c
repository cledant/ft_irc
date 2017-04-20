/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clnt_parse_nick_join_part_quit.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 16:55:41 by cledant           #+#    #+#             */
/*   Updated: 2017/04/20 16:57:43 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

int		clnt_parse_nick_join_part_quit(const t_cmd_arg *arg, t_disp_cmd *cmd,
			const char *begin, const t_func type)
{
	size_t	len;

	if ((len = arg->end - begin - 1) == 0)
		return (0);
	if (len > MAX_PACKET_SIZE)
		return (0);
	cmd->function = type;
	ft_memcpy(cmd->msg, begin + 1, len);
	return (1);
}
