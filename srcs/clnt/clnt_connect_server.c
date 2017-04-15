/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clnt_connect_server.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 18:52:34 by cledant           #+#    #+#             */
/*   Updated: 2017/04/15 19:32:37 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

t_err		clnt_connect_server(const char *addr, const char *port,
				t_clnt_env *env)
{
	if ((env->port = ft_atoi(port)) <= 0 || env->port > 65535)
		return (ERR_PORT_INTERVAL);
	(void)addr;
	return (ERR_NONE);
}
