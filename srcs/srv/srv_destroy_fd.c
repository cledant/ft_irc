/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_destroy_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 15:02:52 by cledant           #+#    #+#             */
/*   Updated: 2017/03/31 15:46:07 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

void	srv_destroy_fd(t_env *env)
{
	int		c;

	c = 0;
	while (c < env->max_fd)
	{
		if (env->list_fd[c].cbuff_read != NULL)
			cbuff_destroy(&(env->list_fd[c].cbuff_read));
		if (env->list_fd[c].cbuff_write != NULL)
			cbuff_destroy(&(env->list_fd[c].cbuff_write));
		c++;
	}
	if (env->list_fd != NULL)
		free(env->list_fd);
}
