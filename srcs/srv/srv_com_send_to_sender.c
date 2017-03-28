/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_com_send_to_sender.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 16:40:39 by cledant           #+#    #+#             */
/*   Updated: 2017/03/28 17:19:01 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

void	srv_com_send_to_sender(t_env *env, t_cmd *cmd)
{
	ft_memcpy(env->list_fd[cmd->fd_sender].cbuff_write->enqueue_buff,
		cmd->cmd, MAX_PACKET_SIZE + 1);
	cbuff_enqueue(env->list_fd[cmd->fd_sender].cbuff_write,
		ft_strlen(env->list_fd[cmd->fd_sender].cbuff_write->enqueue_buff));
}
