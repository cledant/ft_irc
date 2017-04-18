/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clnt_interpret_server_cmd.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 16:23:57 by cledant           #+#    #+#             */
/*   Updated: 2017/04/18 18:42:59 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

int		clnt_interpret_server_cmd(t_clnt_env *env)
{
	cbuff_dequeue(env->cbuff_read, CBUFF_SIZE);
	wprintw(env->out, env->cbuff_read->dequeue_buff);
	return (1);
}
