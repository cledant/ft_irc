/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_com_write_welcome.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 16:49:47 by cledant           #+#    #+#             */
/*   Updated: 2017/03/25 18:38:53 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

int		srv_com_write_welcome(t_env *env, const int fd_sock)
{
	ft_strcat(env->list_fd[fd_sock].cbuff_write->enqueue_buff, BEGIN_PACKET);
	ft_strcat(env->list_fd[fd_sock].cbuff_write->enqueue_buff,
		env->list_fd[fd_sock].nick);
	ft_strcat(env->list_fd[fd_sock].cbuff_write->enqueue_buff, " WELCOME");
	ft_strcat(env->list_fd[fd_sock].cbuff_write->enqueue_buff, END_PACKET);
	cbuff_enqueue(env->list_fd[fd_sock].cbuff_write,
		ft_strlen(env->list_fd[fd_sock].cbuff_write->enqueue_buff));
	return (1);
}
