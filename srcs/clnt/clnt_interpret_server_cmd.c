/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clnt_interpret_server_cmd.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 16:23:57 by cledant           #+#    #+#             */
/*   Updated: 2017/04/18 16:37:02 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

void	clnt_interpret_server_cmd(t_clnt_env *env)
{
	cbuff_dequeue(env->cbuff_read, CBUFF_SIZE);
	wprintw(env->out, env->cbuff_read->dequeue_buff);
}
