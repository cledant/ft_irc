/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_main_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 14:52:57 by cledant           #+#    #+#             */
/*   Updated: 2017/03/22 14:59:36 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

void		srv_main_loop(t_env *env)
{
	while (env->should_loop)
	{
		srv_set_fd_select(env);
		srv_do_select(env);
		srv_check_fd_select(env);
	}
}
