/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clnt_parse_smsg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 11:58:23 by cledant           #+#    #+#             */
/*   Updated: 2017/04/20 12:19:58 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

int			clnt_parse_smsg(const t_cmd_arg *arg, t_disp_cmd *cmd)
{
	char	*ptr_space;
	size_t	size_msg;

	cmd->function = SMSG;
	if ((ptr_space = ft_strnstr(arg->begin, " ", arg->end - arg->begin - 1))
			== NULL)
		return (0);
	size_msg = arg->end - ptr_space;
	if (size_msg == 0 || size_msg > MAX_MSG_LEN)
		return (0);
	ft_memcpy(cmd->msg, ptr_space + 1, size_msg);
	return (1);
}
