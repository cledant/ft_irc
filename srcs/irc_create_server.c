/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   irc_create_server.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 16:04:25 by cledant           #+#    #+#             */
/*   Updated: 2017/03/21 17:26:07 by cledant          ###   ########.fr       */
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
	if ((bind(sock, (sockaddr *)&sin, sizeof(sockaddr_in))) == -1)
		return (ERROR_BIND_SOCKET);
	if ((listen(sock, LISTEN_SIZE)) == -1)
		return (ERROR_LISTEN_SOCKET);
	env->list_fd[sock].type = IRC_SERVER;
	return (ERR_NONE);
}
