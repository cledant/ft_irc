/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_itoa_buffer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 11:15:02 by cledant           #+#    #+#             */
/*   Updated: 2017/04/01 12:03:57 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	inline size_t	ft_strlenitoi(int n)
{
	size_t	result;

	result = 1;
	if (n < 0)
	{
		n = -n;
		result++;
	}
	while (n / 10 > 0)
	{
		result++;
		n = n / 10;
	}
	return (result);
}

static inline void		ft_internal_itoa(int n, size_t len, char *res)
{
	char *cpy_res;

	cpy_res = res;
	if (n < 0)
	{
		n = -n;
		*res = '-';
		len--;
		res++;
	}
	res = res + len - 1;
	while (len != 0)
	{
		*res = n % 10 + '0';
		n = n / 10;
		res--;
		len--;
	}
	res = cpy_res;
}

void					srv_itoa_buffer(int n, char *buffer)
{
	size_t	len;

	len = ft_strlenitoi(n);
	if (n == -2147483648)
	{
		ft_strcpy(buffer, "-2147483648");
		return ;
	}
	ft_internal_itoa(n, len, buffer);
}
