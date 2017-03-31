/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_init_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 12:32:42 by cledant           #+#    #+#             */
/*   Updated: 2017/03/31 15:38:07 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

static inline int			init_list_fd(t_env *env)
{
	size_t		i;

	i = 0;
	ft_bzero(env->list_fd, sizeof(t_fd) * env->max_fd);
	while (i < (size_t)(env->max_fd))
	{
		if (srv_init_fd_free(&(env->list_fd[i]), SET) == 0)
			return (0);
		i++;
	}
	return (1);
}

static inline void			init_list_chan(t_env *env)
{
	size_t		c;

	c = 0;
	while (c < MAX_NB_CHAN)
	{
		srv_init_chan_free(&(env->list_chan[c]));
		c++;
	}
}

static inline t_err			clean_before_return(t_env *env, const t_err err)
{
	if (env->new_data != NULL)
		free(env->new_data);
	if (env->list_fd != NULL)
		srv_destroy_fd(env);
	return (err);
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
	if ((env->new_data = ft_strnew(env->max_fd)) == NULL)
		return (ERR_ALLOC_MEM);
	if ((env->list_fd = (t_fd *)malloc(sizeof(t_fd) * env->max_fd)) == NULL)
		return (clean_before_return(env, ERR_ALLOC_MEM));
	if (init_list_fd(env) == 0)
		return (clean_before_return(env, ERR_ALLOC_MEM));
	init_list_chan(env);
	env->should_loop = 1;
	env->select_max = 0;
	env->select_do = 0;
	env->file_name = argv[0];
	return (ERR_NONE);
}
