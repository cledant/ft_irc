/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_client_write.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 20:02:39 by cledant           #+#    #+#             */
/*   Updated: 2017/03/28 16:48:41 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

void		srv_client_write(t_env *env, int fd_sock)
{
	size_t		sent;

	cbuff_dequeue_till_head_no_change(env->list_fd[fd_sock].cbuff_write);
	sent = send(fd_sock, env->list_fd[fd_sock].cbuff_write->dequeue_buff,
		ft_strlen(env->list_fd[fd_sock].cbuff_write->dequeue_buff), 0);
	cbuff_move_forward_read_head(env->list_fd[fd_sock].cbuff_write, sent);
}
