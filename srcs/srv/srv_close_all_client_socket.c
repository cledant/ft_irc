/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_close_srv_socket.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 15:59:24 by cledant           #+#    #+#             */
/*   Updated: 2017/03/31 16:24:48 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

void	srv_close_all_client_socket(t_env *env)
{
	int		c;

	c = 0;
	while (c < env->max_fd)
	{
		if (env->list_fd[c].type == FD_CLIENT)
			close(c);
		c++;
	}
}
