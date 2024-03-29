/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 15:40:45 by cledant           #+#    #+#             */
/*   Updated: 2017/04/28 11:39:20 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

static int				print_err(const t_err code, const char *str)
{
	if (code == ERR_NB_ARG)
		printf("Usage : %s [machine [port]]\n", str);
	else if (code == ERR_ARG_NOT_INT || code == ERR_PORT_INTERVAL)
		printf("%s : Invalid port\n", str);
	else if (code == ERR_GET_RLIM)
		printf("%s : Error getting system limits\n", str);
	else if (code == ERR_MAX_FD)
		printf("%s : Invalid max fd\n", str);
	else if (code == ERR_ALLOC_MEM)
		printf("%s : Can't allocate memory\n", str);
	else if (code == ERR_UNKNOWN_PROTOCOL)
		printf("%s : Unknown protocol requested\n", str);
	else if (code == ERR_OPEN_SOCKET)
		printf("%s : Can't open socket\n", str);
	else if (code == ERR_BIND_SOCKET)
		printf("%s : Can't bind socket\n", str);
	else if (code == ERR_LISTEN_SOCKET)
		printf("%s : Can't listen socket\n", str);
	else if (code == ERR_SERV_NOT_FOUND)
		printf("%s : Can't find server\n", str);
	else if (code == ERR_SERV_CONNECT)
		printf("%s : Can't connect to server\n", str);
	else if (code == ERR_INIT_NCURSES)
		printf("%s : Can't init ncurses\n", str);
	return (-1);
}

static inline void		print_err_ncurses(const t_err code, const char *str,
							t_clnt_env *env)
{
	if (code == ERR_NB_ARG)
		wprintw(env->out, "Usage : %s [machine [port]]\n", str);
	else if (code == ERR_ARG_NOT_INT || code == ERR_PORT_INTERVAL)
		wprintw(env->out, "%s : Invalid port\n", str);
	else if (code == ERR_GET_RLIM)
		wprintw(env->out, "%s : Error getting system limits\n", str);
	else if (code == ERR_MAX_FD)
		wprintw(env->out, "%s : Invalid max fd\n", str);
	else if (code == ERR_ALLOC_MEM)
		wprintw(env->out, "%s : Can't allocate memory\n", str);
	else if (code == ERR_UNKNOWN_PROTOCOL)
		wprintw(env->out, "%s : Unknown protocol requested\n", str);
	else if (code == ERR_OPEN_SOCKET)
		wprintw(env->out, "%s : Can't open socket\n", str);
	else if (code == ERR_BIND_SOCKET)
		wprintw(env->out, "%s : Can't bind socket\n", str);
	else if (code == ERR_LISTEN_SOCKET)
		wprintw(env->out, "%s : Can't listen socket\n", str);
	else if (code == ERR_SERV_NOT_FOUND)
		wprintw(env->out, "%s : Can't find server\n", str);
	else if (code == ERR_SERV_CONNECT)
		wprintw(env->out, "%s : Can't connect to server\n", str);
	wrefresh(env->out);
}

static inline t_err		default_connect(int argc, char **argv, t_clnt_env *env)
{
	t_err	err;

	if (argc == 1)
	{
		if ((err = clnt_connect_server(DEFAULT_IP, DEFAULT_PORT, env))
				!= ERR_NONE)
			return (err);
	}
	else if (argc == 2)
	{
		if ((err = clnt_connect_server(argv[1], DEFAULT_PORT, env))
				!= ERR_NONE)
			return (err);
	}
	else if (argc == 3)
	{
		if ((err = clnt_connect_server(argv[1], argv[2], env))
				!= ERR_NONE)
			return (err);
	}
	else if (argc > 3)
		return (ERR_NB_ARG);
	return (ERR_NONE);
}

int						main(int argc, char **argv)
{
	t_clnt_env		env;
	t_err			err;

	ft_bzero(&env, sizeof(t_clnt_env));
	clnt_get_env(&env);
	if ((err = clnt_init_env(&env, argv)) != ERR_NONE)
	{
		clnt_destroy_env(&env);
		return (print_err(err, argv[0]));
	}
	if ((err = clnt_init_ncurses(&env)) != ERR_NONE)
	{
		clnt_close_ncurses(&env);
		clnt_destroy_env(&env);
		return (print_err(err, argv[0]));
	}
	if ((err = default_connect(argc, argv, &env)) != ERR_NONE)
	{
		clnt_disconnect(&env);
		print_err_ncurses(err, argv[0], &env);
	}
	clnt_set_signal();
	clnt_main_loop(&env);
	clnt_close_client();
	return (0);
}
