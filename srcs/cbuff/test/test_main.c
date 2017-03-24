/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 18:10:10 by cledant           #+#    #+#             */
/*   Updated: 2017/03/24 18:21:01 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

int		main(void)
{
	t_cbuff		*cbuff;
	char		*test_1 = "COUCOU TEST!";

	if ((cbuff = cbuff_create(32)) == NULL)
	{
		printf("FAILED TO INIT !\n");
		return (0);
	}
	ft_memcpy(cbuff->enqueue_buff, test_1, ft_strlen(test_1));
	cbuff_enqueue(cbuff, ft_strlen(test_1));
	cbuff_dequeue(cbuff, 32);
	printf("DEQUEUE BUFFER : %s\n", cbuff->dequeue_buff);
	cbuff_destroy(&cbuff);
	return (0);
}
