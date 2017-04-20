/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clnt_disp_nick.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 16:44:09 by cledant           #+#    #+#             */
/*   Updated: 2017/04/20 16:48:47 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

int		clnt_disp_nick(const t_disp_cmd *cmd, t_clnt_env *env)
{
	wprintw(env->out, "\n%s changed nick into %s", cmd->msg, cmd->nick);
	wrefresh(env->out);
	return (1);
}
