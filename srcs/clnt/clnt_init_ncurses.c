/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clnt_init_ncurses.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 09:46:40 by cledant           #+#    #+#             */
/*   Updated: 2017/04/17 11:51:52 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

t_err	clnt_init_ncurses(t_clnt_env *env)
{
	if (initscr() == NULL)
		return (ERR_INIT_NCURSES);
	if (cbreak() == ERR)
		return (ERR_INIT_NCURSES);
	if (echo() == ERR)
		return (ERR_INIT_NCURSES);
	if ((env->in = newwin(1, COLS, LINES - 1, 0)) == NULL)
		return (ERR_INIT_NCURSES);
	if ((env->out = newwin(LINES - 1, COLS, 0, 0)) == NULL)
		return (ERR_INIT_NCURSES);
	if (wmove(env->out, LINES - 2, 0) == ERR)
		return (ERR_INIT_NCURSES);
	if (scrollok(env->out, TRUE) == ERR)
		return (ERR_INIT_NCURSES);
	refresh();
	return (ERR_NONE);
}
