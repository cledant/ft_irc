/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_do_select.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 16:06:55 by cledant           #+#    #+#             */
/*   Updated: 2017/03/22 19:26:07 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

void		srv_do_select(t_env *env)
{
	struct timeval		tv;

	tv.tv_sec = 1;
	tv.tv_usec = 0;
	env->select_do = select(env->select_max + 1, &(env->fdset_r),
		&(env->fdset_w), NULL, &tv);
	if (env->select_do == -1)
		printf("%s : Select failed !\n", env->file_name);
}
