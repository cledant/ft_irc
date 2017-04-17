/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clnt_main_loop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 12:00:02 by cledant           #+#    #+#             */
/*   Updated: 2017/04/17 18:34:09 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

void		clnt_main_loop(t_clnt_env *env)
{
	while (env->should_loop)
	{
		wresize(env->out, LINES - 1, COLS);
		mvwin(env->in, LINES - 1, 0);
		wmove(env->out, LINES - 2, 0);
		clnt_set_fd_select(env);
		clnt_do_select(env);
		if (env->select_do > 0)
			clnt_check_fd_select(env);
		clnt_interpret_new_data(env);
		clnt_display(env);
	}
}
