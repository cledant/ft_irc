/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clnt_disp_join.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 17:25:08 by cledant           #+#    #+#             */
/*   Updated: 2017/04/20 17:25:13 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

int		clnt_disp_join(const t_disp_cmd *cmd, t_clnt_env *env)
{
	wprintw(env->out, "\n%s joined %s", cmd->nick, cmd->msg);
	wrefresh(env->out);
	return (1);
}
