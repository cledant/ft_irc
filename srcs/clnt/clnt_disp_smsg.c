/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clnt_disp_smsg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 12:13:53 by cledant           #+#    #+#             */
/*   Updated: 2017/04/20 21:27:55 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

int		clnt_disp_smsg(const t_disp_cmd *cmd, t_clnt_env *env)
{
	wprintw(env->out, "%s\n", cmd->msg);
	wrefresh(env->out);
	return (1);
}
