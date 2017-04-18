/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clnt_destroy_env.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 12:27:15 by cledant           #+#    #+#             */
/*   Updated: 2017/04/18 12:29:54 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

void	clnt_destroy_env(t_clnt_env *env)
{
	if (env->cbuff_read != NULL)
		cbuff_destroy(&(env->cbuff_read));
	if (env->cbuff_write != NULL)
		cbuff_destroy(&(env->cbuff_write));
}
