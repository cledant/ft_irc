/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clnt_disp_part.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 17:05:55 by cledant           #+#    #+#             */
/*   Updated: 2017/04/20 17:26:07 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

int		clnt_disp_part(const t_disp_cmd *cmd, t_clnt_env *env)
{
	wprintw(env->out, "\n%s left %s", cmd->nick, cmd->msg);
	wrefresh(env->out);
	return (1);
}
