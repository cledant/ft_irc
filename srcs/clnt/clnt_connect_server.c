/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clnt_connect_server.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 18:52:34 by cledant           #+#    #+#             */
/*   Updated: 2017/04/16 20:11:19 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

static int	connect_to_serv(t_clnt_env *env)
{
	(void)env;
	return (0);
}

t_err		clnt_connect_server(const char *addr, const char *port,
				t_clnt_env *env)
{
	struct addrinfo		hints;
	struct protoent		*pe;

	if (ft_is_not_int((char *)port) == 1)
		return (ERR_ARG_NOT_INT);
	env->port = ft_atoi(port);
	if (env->port <= 0 || env->port > 65535)
		return (ERR_PORT_INTERVAL);
	if ((pe = getprotobyname("tcp")) == NULL)
		return (ERR_UNKNOWN_PROTOCOL);
	ft_bzero(&hints, sizeof(struct addrinfo));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = pe->p_proto;
	if (getaddrinfo(addr, port, &hints, &(env->result)) != 0)
		return (ERR_SERV_NOT_FOUND);
	if (connect_to_serv(env) == 0)
		return (ERR_SERV_CONNECT);
	return (ERR_NONE);
}
