/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clnt_disp_privmsg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 18:48:24 by cledant           #+#    #+#             */
/*   Updated: 2017/04/28 11:52:55 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

int		clnt_disp_privmsg(const t_disp_cmd *cmd, t_clnt_env *env)
{
	if (cmd->msg_nick[0] != '\0')
		wprintw(env->out, "<Private msg>%s: %s\n", cmd->nick, cmd->msg);
	else
		wprintw(env->out, "<%s>%s:%s\n", cmd->msg_chan, cmd->nick,
			cmd->msg);
	wrefresh(env->out);
	return (1);
}
