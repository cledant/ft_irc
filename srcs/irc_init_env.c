/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   irc_init_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 12:32:42 by cledant           #+#    #+#             */
/*   Updated: 2017/03/21 15:55:18 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

static inline void			init_list_fd(t_env *env)
{
	size_t		i;

	i = 0;
	while (i < (size_t)(env->max_fd))
	{
		irc_init_fd(&(env->list_fd[i]));
		i++;
	}
}

t_err						irc_init_env(t_env *env, const char **argv)
{
	struct rlimit	r_lim;

	if (ft_is_not_int(argv[1]) == 1)
		return (ERR_ARG_NOT_INT);
	env->port = ft_atoi(argv[1]);
	if (getrlimit(RLIMIT_NOFILE, &r_lim) == -1)
		return (ERR_GET_RLIM);
	if ((env->maxfd = r_lim.rlim_cur) <= 0)
		return (ERR_MAX_FD);
	if ((env->list_fd = (t_fd *)malloc(sizeof(t_fd) * env->maxfd)) == NULL)
		return (ERR_ALLOC_MEM);
	init_list_fd(env);
	return (ERR_NONE);
}
