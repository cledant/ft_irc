/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clnt_disp_welcome.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 13:41:56 by cledant           #+#    #+#             */
/*   Updated: 2017/04/20 21:28:21 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

int		clnt_disp_welcome(const t_disp_cmd *cmd, t_clnt_env *env)
{
	wprintw(env->out, "Welcome to this server !\nYour nick is: %s\n",
		cmd->nick);
	wrefresh(env->out);
	return (1);
}
