/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_get_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 12:28:48 by cledant           #+#    #+#             */
/*   Updated: 2017/03/31 14:08:08 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

t_env	*srv_get_env(t_env *env)
{
	static t_env	*save = NULL;
	static int		flag = 0;

	if (save == NULL && flag == 0)
	{
		save = env;
		flag = 1;
	}
	return (save);
}
