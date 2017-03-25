/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_client_read.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 20:07:18 by cledant           #+#    #+#             */
/*   Updated: 2017/03/25 18:57:34 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

void		srv_client_read(t_env *env, int fd_sock)
{
	int		rvd;

	if ((rvd = recv(fd_sock, env->list_fd[fd_sock].cbuff_read->enqueue_buff,
			CBUFF_SIZE, 0)) <= 0)
	{
		close(fd_sock);
		srv_init_fd_free(&(env->list_fd[fd_sock]), RESET);
		printf("%s : Client ID : %d disconnected !\n", env->file_name, fd_sock);
		return ;
	}
	printf("%s : Client ID : %d sent a packet of %d bytes ! Content :%s\n",
		env->file_name, fd_sock, rvd,
		env->list_fd[fd_sock].cbuff_read->enqueue_buff);
	cbuff_enqueue(env->list_fd[fd_sock].cbuff_read, rvd);
}
