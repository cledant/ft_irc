/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_set_signal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 13:09:16 by cledant           #+#    #+#             */
/*   Updated: 2017/03/31 14:07:56 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

void		srv_set_signal(void)
{
	signal(SIGINT, (void (*)(int))srv_shutdown);
	signal(SIGHUP, (void (*)(int))srv_shutdown);
	signal(SIGQUIT, (void (*)(int))srv_shutdown);
	signal(SIGILL, (void (*)(int))srv_shutdown);
	signal(SIGTRAP, (void (*)(int))srv_shutdown);
	signal(SIGABRT, (void (*)(int))srv_shutdown);
	signal(SIGEMT, (void (*)(int))srv_shutdown);
	signal(SIGFPE, (void (*)(int))srv_shutdown);
	signal(SIGBUS, (void (*)(int))srv_shutdown);
	signal(SIGSEGV, (void (*)(int))srv_shutdown);
	signal(SIGSYS, (void (*)(int))srv_shutdown);
	signal(SIGPIPE, (void (*)(int))srv_shutdown);
	signal(SIGALRM, (void (*)(int))srv_shutdown);
	signal(SIGTERM, (void (*)(int))srv_shutdown);
	signal(SIGTSTP, SIG_IGN);
	signal(SIGTTIN, (void (*)(int))srv_shutdown);
	signal(SIGTTOU, (void (*)(int))srv_shutdown);
	signal(SIGXCPU, (void (*)(int))srv_shutdown);
	signal(SIGXFSZ, (void (*)(int))srv_shutdown);
	signal(SIGVTALRM, (void (*)(int))srv_shutdown);
	signal(SIGPROF, (void (*)(int))srv_shutdown);
	signal(SIGUSR1, (void (*)(int))srv_shutdown);
	signal(SIGUSR2, (void (*)(int))srv_shutdown);
}
