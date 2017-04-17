/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_interpret_new_data.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 10:25:00 by cledant           #+#    #+#             */
/*   Updated: 2017/04/17 15:49:39 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

void					clnt_interpret_new_data(t_clnt_env *env)
{
	if (ft_strlen(env->buff) > 0)
	{
		//TODO convert user cmd to srv cmd
		ft_memcpy(env->cbuff_write->enqueue_buff, env->buff,
			ft_strlen(env->buff));
		cbuff_enqueue(env->cbuff_write,
			ft_strlen(env->cbuff_write->enqueue_buff));
		ft_bzero(env->buff, MAX_MSG_LEN + 1);
	}
	//TODO convert srv cmd to display
	cbuff_dequeue(env->cbuff_read, CBUFF_SIZE);
}
