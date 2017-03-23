/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_main_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 14:52:57 by cledant           #+#    #+#             */
/*   Updated: 2017/03/23 17:31:29 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

void		srv_main_loop(t_env *env)
{
	while (env->should_loop)
	{
		srv_set_fd_select(env);
		srv_do_select(env);
		if (env->select_do > 0)
			srv_check_fd_select(env);
	}
}
