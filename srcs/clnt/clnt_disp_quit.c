/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clnt_disp_quit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 17:26:49 by cledant           #+#    #+#             */
/*   Updated: 2017/04/20 21:27:38 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

int		clnt_disp_quit(const t_disp_cmd *cmd, t_clnt_env *env)
{
	wprintw(env->out, "%s disconnected from server. Reason : %s\n",
		cmd->nick, cmd->msg);
	wrefresh(env->out);
	return (1);
}
