/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_do_select.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 16:06:55 by cledant           #+#    #+#             */
/*   Updated: 2017/03/29 03:17:01 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

void		srv_do_select(t_env *env)
{
	env->select_do = select(env->select_max + 1, &(env->fdset_r),
		&(env->fdset_w), NULL, NULL);
	if (env->select_do == -1)
		printf("%s : Select failed !\n", env->file_name);
}
