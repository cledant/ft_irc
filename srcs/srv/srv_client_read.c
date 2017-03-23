/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_client_read.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 20:07:18 by cledant           #+#    #+#             */
/*   Updated: 2017/03/23 16:08:45 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

void		srv_client_read(t_env *env, int fd_sock)
{
	int		rvd;

	if ((rvd = recv(fd_sock, env->list_fd[fd_sock].buff_read,
			IRC_BUFF_SIZE, 0)) <= 0)
	{
		close(fd_sock);
		srv_init_fd_free(&(env->list_fd[fd_sock]));
		printf("%s : Client ID : %d disconnected !\n", env->file_name, fd_sock);
		return ;
	}
	printf("%s : Client ID : %d said : %s\n", env->file_name, fd_sock,
		env->list_fd[fd_sock].buff_read);
	ft_bzero(env->list_fd[fd_sock].buff_read, IRC_BUFF_SIZE + 1);
}
