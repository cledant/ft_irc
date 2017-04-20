/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clnt_parse_names.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 20:29:30 by cledant           #+#    #+#             */
/*   Updated: 2017/04/20 20:55:15 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

int		clnt_parse_names(const t_cmd_arg *arg,
			t_disp_cmd *cmd, const char *begin)
{
	char	*ptr_chan_nick;
	char	*ptr_number;
	size_t	len;

	if ((len = arg->end - begin + 1) == 0)
		return (0);
	if ((ptr_chan_nick = ft_strnstr(begin + 1, " ", len)) == NULL)
		return (0);
	len = ptr_chan_nick - begin - 1;
	if (*(begin + 1) != '#')
		return (0);
	if (len == 0 || len > MAX_CHAN_NAME_LEN)
		return (0);
	ft_memcpy(cmd->msg_chan, begin + 1, len);
	if ((ptr_number = ft_strnstr(ptr_chan_nick + 1, " ", len)) == NULL)
		return (0);
	len = ptr_number - ptr_chan_nick - 1;
	if (len == 0 || len > MAX_CHAN_NAME_LEN)
		return (0);
	ft_memcpy(cmd->msg_nbr, ptr_chan_nick + 1, len);
	if ((len = arg->end - ptr_number) > MAX_MSG_LEN)
		return (0);
	ft_memcpy(cmd->msg, ptr_number + 1, len - 1);
	cmd->function = NAMES;
	return (1);
}
