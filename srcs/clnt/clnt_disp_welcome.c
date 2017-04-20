/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clnt_disp_welcome.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 13:41:56 by cledant           #+#    #+#             */
/*   Updated: 2017/04/20 13:41:58 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

int		clnt_disp_welcome(const t_disp_cmd *cmd, t_clnt_env *env)
{
	wprintw(env->out, "\nWelcome to this server : %s!", cmd->nick);
	wrefresh(env->out);
	return (1);
}
