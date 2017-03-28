/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_disconnect_client.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 14:56:14 by cledant           #+#    #+#             */
/*   Updated: 2017/03/28 13:43:54 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

void		srv_disconnect_client(t_env *env, const int fd_sock,
				const t_err err)
{
	close(fd_sock);
	srv_init_fd_free(&(env->list_fd[fd_sock]), RESET);
	if (err == ERR_CLOSE_DISCONNECTED)
	{
		printf("%s : Client ID : %d disconnected !\n", env->file_name,
			fd_sock);
	}
	else if (err == ERR_CLOSE_OVERWRITE)
	{
		printf("%s : Client ID : %d kicked : Buffer full !\n",
			env->file_name, fd_sock);
	}
	else if (err == ERR_CLOSE_INIT_NAME)
	{
		printf("%s : Client ID : %d kicked : Can't set init name !\n",
			env->file_name, fd_sock);
	}
}
