/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clnt_get_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 12:22:54 by cledant           #+#    #+#             */
/*   Updated: 2017/04/18 13:28:43 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

t_clnt_env		*clnt_get_env(t_clnt_env *env)
{
	static t_clnt_env	*save = NULL;
	static int			flag = 0;

	if (save == NULL && flag == 0)
	{
		save = env;
		flag = 1;
	}
	return (save);
}
