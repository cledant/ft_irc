/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clnt_do_select.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 12:35:44 by cledant           #+#    #+#             */
/*   Updated: 2017/04/17 17:30:51 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

void		clnt_do_select(t_clnt_env *env)
{
	env->select_do = select(env->socket + 1, &(env->fdset_r),
		&(env->fdset_w), NULL, NULL);
}
