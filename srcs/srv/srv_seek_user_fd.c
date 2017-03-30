/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_seek_user_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 21:41:06 by cledant           #+#    #+#             */
/*   Updated: 2017/03/30 22:55:16 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

int		srv_seek_user_fd(t_env *env, const char *user_name)
{
	int		c;

	c = 0;
	while (c < env->max_fd)
	{
		if (ft_strcmp(user_name, env->list_fd[c].nick) == 0)
			return (c);
		c++;
	}
	return (-1);
}
