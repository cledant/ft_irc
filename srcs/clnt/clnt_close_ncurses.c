/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clnt_close_ncurses.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 12:33:29 by cledant           #+#    #+#             */
/*   Updated: 2017/04/18 12:57:14 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

void	clnt_close_ncurses(t_clnt_env *env)
{
	if (env->in != NULL)
	{
		werase(env->in);
		delwin(env->in);
	}
	if (env->out != NULL)
	{
		werase(env->out);
		delwin(env->out);
	}
	endwin();
}
