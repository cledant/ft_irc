/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clnt_main_loop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 12:00:02 by cledant           #+#    #+#             */
/*   Updated: 2017/04/17 12:03:41 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

void		clnt_main_loop(t_env *env)
{
	while (env->should_loop)
	{
		clnt_set_fd_select(env);
		clnt_do_select(env);
		if (env->select_do > 0)
			clnt_check_fd_select(env);
//		clnt_interpret_new_data(env);
	}
}
