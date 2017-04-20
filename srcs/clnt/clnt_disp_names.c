/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clnt_disp_names.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 20:52:01 by cledant           #+#    #+#             */
/*   Updated: 2017/04/20 20:54:17 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

int		clnt_disp_names(const t_disp_cmd *cmd, t_clnt_env *env)
{
	wprintw(env->out, "\nPeople in %s:%s\n%s", cmd->msg_chan, cmd->msg_nbr,
		cmd->msg);
	wrefresh(env->out);
	return (1);
}
