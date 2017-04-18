/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clnt_init_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 16:25:51 by cledant           #+#    #+#             */
/*   Updated: 2017/04/18 22:35:38 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

t_err		clnt_init_env(t_clnt_env *env, char **argv)
{
	struct rlimit	r_lim;

	if ((env->cbuff_read = cbuff_create(CBUFF_SIZE)) == NULL)
		return (ERR_ALLOC_MEM);
	if ((env->cbuff_write = cbuff_create(CBUFF_SIZE)) == NULL)
		return (ERR_ALLOC_MEM);
	if (getrlimit(RLIMIT_NOFILE, &r_lim) == -1)
		return (ERR_GET_RLIM);
	if ((env->max_fd = r_lim.rlim_cur) <= 0)
		return (ERR_MAX_FD);
	env->should_loop = 1;
	env->file_name = argv[0];
	return (ERR_NONE);
}
