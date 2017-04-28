/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_is_nick_valid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 11:05:53 by cledant           #+#    #+#             */
/*   Updated: 2017/04/28 11:29:25 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

static int		exception_char(const int ch)
{
	static char		*list = "+-=/*_&$|%";
	size_t			c;

	c = 0;
	while (list[c] != '\0')
	{
		if ((int)list[c] == ch)
			return (1);
		c++;
	}
	return (0);
}

int				srv_is_nick_valid(const char *name)
{
	size_t		c;

	c = 0;
	while (name[c] != '\0')
	{
		if (ft_isalnum(name[c]) == 0 && exception_char(name[c]) == 0)
			return (0);
		c++;
	}
	return (1);
}
