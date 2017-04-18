/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clnt_set_signal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 13:08:16 by cledant           #+#    #+#             */
/*   Updated: 2017/04/18 13:28:57 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

void		clnt_set_signal(void)
{
	signal(SIGINT, (void (*)(int))clnt_close_client);
	signal(SIGHUP, (void (*)(int))clnt_close_client);
	signal(SIGQUIT, (void (*)(int))clnt_close_client);
	signal(SIGILL, (void (*)(int))clnt_close_client);
	signal(SIGTRAP, (void (*)(int))clnt_close_client);
	signal(SIGABRT, (void (*)(int))clnt_close_client);
	signal(SIGEMT, (void (*)(int))clnt_close_client);
	signal(SIGFPE, (void (*)(int))clnt_close_client);
	signal(SIGBUS, (void (*)(int))clnt_close_client);
	signal(SIGSEGV, (void (*)(int))clnt_close_client);
	signal(SIGSYS, (void (*)(int))clnt_close_client);
	signal(SIGPIPE, (void (*)(int))clnt_close_client);
	signal(SIGALRM, (void (*)(int))clnt_close_client);
	signal(SIGTERM, (void (*)(int))clnt_close_client);
	signal(SIGTSTP, SIG_IGN);
	signal(SIGTTIN, (void (*)(int))clnt_close_client);
	signal(SIGTTOU, (void (*)(int))clnt_close_client);
	signal(SIGXCPU, (void (*)(int))clnt_close_client);
	signal(SIGXFSZ, (void (*)(int))clnt_close_client);
	signal(SIGVTALRM, (void (*)(int))clnt_close_client);
	signal(SIGPROF, (void (*)(int))clnt_close_client);
	signal(SIGUSR1, (void (*)(int))clnt_close_client);
	signal(SIGUSR2, (void (*)(int))clnt_close_client);
}
