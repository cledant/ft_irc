/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clnt_cmd_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 22:44:12 by cledant           #+#    #+#             */
/*   Updated: 2017/04/20 21:23:06 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

int		clnt_cmd_exit(const t_cmd_arg *arg, t_clnt_env *env)
{
	if (arg->end - arg->begin == 4)
		clnt_close_client();
	else
		wprintw(env->out, "Invalid use of /exit\n");
	return (1);
}
