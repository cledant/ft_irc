/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clnt_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 15:27:36 by cledant           #+#    #+#             */
/*   Updated: 2017/04/17 15:45:19 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

void		clnt_display(t_clnt_env *env)
{
	wprintw(env->out, env->cbuff_read->dequeue_buff);
	wrefresh(env->out);
}
