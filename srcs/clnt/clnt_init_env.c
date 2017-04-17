/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clnt_init_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 16:25:51 by cledant           #+#    #+#             */
/*   Updated: 2017/04/17 12:00:32 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

t_err		clnt_init_env(t_clnt_env *env)
{
	struct rlimit	r_lim;
	struct protoent	*pe;

	if ((env->cbuff_read = cbuff_create(CBUFF_SIZE)) == NULL)
		return (ERR_ALLOC_MEM);
	if ((env->cbuff_write = cbuff_create(CBUFF_SIZE)) == NULL)
		return (ERR_ALLOC_MEM);
	if (getrlimit(RLIMIT_NOFILE, &r_lim) == -1)
		return (ERR_GET_RLIM);
	if ((env->max_fd = r_lim.rlim_cur) <= 0)
		return (ERR_MAX_FD);
	if ((pe = getprotobyname("tcp")) == NULL)
		return (ERR_UNKNOWN_PROTOCOL);
	if ((env->socket = socket(PF_INET, SOCK_STREAM, pe->p_proto)) == -1)
		return (ERR_OPEN_SOCKET);
	if (env->socket >= env->max_fd)
	{
		close(env->socket);
		return (ERR_OPEN_SOCKET);
	}
	env->should_loop = 1;
	return (ERR_NONE);
}
