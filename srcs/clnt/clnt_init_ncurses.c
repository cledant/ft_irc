/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clnt_init_ncurses.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 09:46:40 by cledant           #+#    #+#             */
/*   Updated: 2017/04/18 11:28:13 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

t_err	clnt_init_ncurses(t_clnt_env *env)
{
	if (initscr() == NULL)
		return (ERR_INIT_NCURSES);
	if ((env->in = newwin(1, 500, LINES - 1, 0)) == NULL)
		return (ERR_INIT_NCURSES);
	if ((env->out = newwin(LINES - 1, COLS, 0, 0)) == NULL)
		return (ERR_INIT_NCURSES);
	echo();
	wmove(env->out, LINES - 2, 0);
	scrollok(env->out, TRUE);
	keypad(env->in, TRUE);
	cbreak();
	wtimeout(env->in, 2500);
	wrefresh(env->in);
	wrefresh(env->out);
	return (ERR_NONE);
}
