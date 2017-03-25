/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_is_nick_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 16:36:57 by cledant           #+#    #+#             */
/*   Updated: 2017/03/25 18:38:36 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

int		srv_is_nick_free(t_env *env, const int fd_sock, const char *nick)
{
	size_t		c;

	c = 0;
	while (c < (size_t)env->max_fd)
	{
		if (env->list_fd[c].type == FD_CLIENT && c != (size_t)fd_sock)
		{
			if (ft_strcmp(env->list_fd[c].nick, nick) == 0)
				return (0);
		}
		c++;
	}
	return (1);
}
