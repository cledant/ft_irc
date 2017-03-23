/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_init_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 12:32:42 by cledant           #+#    #+#             */
/*   Updated: 2017/03/23 16:01:31 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

static inline void			init_list_fd(t_env *env)
{
	size_t		i;

	i = 0;
	while (i < (size_t)(env->max_fd))
	{
		srv_init_fd_free(&(env->list_fd[i]));
		i++;
	}
}

t_err						srv_init_env(t_env *env, char **argv)
{
	struct rlimit	r_lim;

	if (ft_is_not_int(argv[1]) == 1)
		return (ERR_ARG_NOT_INT);
	env->port = ft_atoi(argv[1]);
	if (env->port <= 0 || env->port > 65535)
		return (ERR_PORT_INTERVAL);
	if (getrlimit(RLIMIT_NOFILE, &r_lim) == -1)
		return (ERR_GET_RLIM);
	if ((env->max_fd = r_lim.rlim_cur) <= 0)
		return (ERR_MAX_FD);
	if ((env->list_fd = (t_fd *)malloc(sizeof(t_fd) * env->max_fd)) == NULL)
		return (ERR_ALLOC_MEM);
	init_list_fd(env);
	env->should_loop = 1;
	env->select_max = 0;
	env->file_name = argv[0];
	return (ERR_NONE);
}
