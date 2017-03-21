/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   irc_create_server.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 16:04:25 by cledant           #+#    #+#             */
/*   Updated: 2017/03/21 17:01:50 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

t_err		irc_create_server(t_env *env)
{
	int					sock;
	struct protoent		*pe;
	struct sockaddr_in	sin;

	if ((pe = getprotobyname("tcp")) == NULL)
		return (ERR_UNKNOWN_PROTOCOL);
	if ((sock = socket(PF_INET, SOCK_STREAM, pe->proto)) == -1)
		return (ERR_OPEN_SOCKET);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(env->port);
	sin.sin_addr.s_addr = INADDR_ANY;

	return (ERR_NONE);
}
