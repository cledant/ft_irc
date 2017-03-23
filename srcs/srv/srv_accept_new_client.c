/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_accept_new_client.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 17:28:25 by cledant           #+#    #+#             */
/*   Updated: 2017/03/23 17:30:50 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

void	srv_accept_new_client(t_env *env, int fd_sock)
{
	int						new_sock;
	struct sockaddr_in		sock_in;
	socklen_t				sock_in_len;

	sock_in_len = sizeof(struct sockaddr_in);
	if ((new_sock = accept(fd_sock, (struct sockaddr *)&sock_in, &sock_in_len))
		== -1)
	{
		printf("%s : Failed to connect new client !\n", env->file_name);
		return ;
	}
	printf("%s : New client ! ID : %d from %s: %d\n", env->file_name, new_sock,
		inet_ntoa(sock_in.sin_addr), ntohs(sock_in.sin_port));
	srv_init_fd_client(&(env->list_fd[new_sock]));
}
