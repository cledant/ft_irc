/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 15:40:45 by cledant           #+#    #+#             */
/*   Updated: 2017/04/15 19:32:08 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

static int		print_err(const t_err code, const char *str)
{
	if (code == ERR_NB_ARG)
		printf("Usage : %s <port>\n", str);
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
	return (-1);
}

int		main(int argc, char **argv)
{
	t_clnt_env		env;
	t_err			err;

	ft_bzero(&env, sizeof(t_clnt_env));
	if (argc == 1)
	{
		if ((err = clnt_connect_server(DEFAULT_IP, DEFAULT_PORT, &env))
				!= ERR_NONE)
			return (print_err(err, argv[0]));
	}
	else if (argc == 2)
	{
		if ((err = clnt_connect_server(argv[1], DEFAULT_PORT, &env))
				!= ERR_NONE)
			return (print_err(err, argv[0]));
	}
	else if (argc == 3)
	{
		if ((err = clnt_connect_server(argv[1], argv[2], &env))
				!= ERR_NONE)
			return (print_err(err, argv[0]));
	}
	else
		return (print_err(ERR_NB_ARG, argv[0]));
	while(1);
	return (0);
}
