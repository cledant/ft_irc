/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 16:09:50 by cledant           #+#    #+#             */
/*   Updated: 2017/03/31 12:13:40 by cledant          ###   ########.fr       */
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

int				main(int argc, char **argv)
{
	t_env	env;
	t_err	err;

	if (argc != 2)
		return (print_err(ERR_NB_ARG, argv[0]));
	if ((err = srv_init_env(&env, argv)) != ERR_NONE)
		return (print_err(err, argv[0]));
	if ((err = srv_create_server(&env)) != ERR_NONE)
		return (print_err(err, argv[0]));
	printf("%s : Ready !\n", argv[0]);
	srv_main_loop(&env);
	return (0);
}
