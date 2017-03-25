/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 18:10:10 by cledant           #+#    #+#             */
/*   Updated: 2017/03/25 11:15:01 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

int		main(void)
{
	t_cbuff		*cbuff;
	static char	*test_1 = "COUCOU TEST!";
	static char	*test_2 = "ABCDEFGHIJ";
	size_t		c = 0;

	if ((cbuff = cbuff_create(32)) == NULL)
	{
		printf("FAILED TO INIT !\n");
		return (0);
	}
	printf("==========================TEST 1=================================\n");
	while (c < 100)
	{
		ft_memcpy(cbuff->enqueue_buff, test_1, ft_strlen(test_1));
		printf("         INIT BUFFER : %s\n", cbuff->buff);
		printf("R_POS = %ld\n", cbuff->r_pos);
		printf("W_POS = %ld\n", cbuff->w_pos);
		printf("ENQUEUE CUMUL = %ld\n", cbuff->enqueue_cumul);
		printf("OVERWRITE = %ld\n", cbuff->overwrite);
		cbuff_enqueue(cbuff, ft_strlen(test_1));
		printf("APRES ENQUEUE BUFFER : %s\n", cbuff->buff);
		printf("R_POS = %ld\n", cbuff->r_pos);
		printf("W_POS = %ld\n", cbuff->w_pos);
		printf("ENQUEUE CUMUL = %ld\n", cbuff->enqueue_cumul);
		printf("OVERWRITE = %ld\n", cbuff->overwrite);
		cbuff_dequeue(cbuff, ft_strlen(test_1));
		printf("DEQUEUE BUFFER : %s\n", cbuff->dequeue_buff);
		printf("APRES DEQUEUE BUFFER : %s\n", cbuff->buff);
		printf("R_POS = %ld\n", cbuff->r_pos);
		printf("W_POS = %ld\n", cbuff->w_pos);
		printf("ENQUEUE CUMUL = %ld\n", cbuff->enqueue_cumul);
		printf("OVERWRITE = %ld\n", cbuff->overwrite);
		c++;
	}
	c = 1;
	cbuff_destroy(&cbuff);
	if ((cbuff = cbuff_create(36)) == NULL)
	{
		printf("FAILED TO INIT !\n");
		return (0);
	}
	printf("===========================TEST 2==============================\n");
	while (c < 100)
	{
		ft_memcpy(cbuff->enqueue_buff, test_2, ft_strlen(test_2));
		printf("         INIT BUFFER : %s\n", cbuff->buff);
		printf("R_POS = %ld\n", cbuff->r_pos);
		printf("W_POS = %ld\n", cbuff->w_pos);	
		printf("OVERWRITE = %ld\n", cbuff->overwrite);
		cbuff_enqueue(cbuff, ft_strlen(test_2));
		printf("APRES ENQUEUE BUFFER : %s\n", cbuff->buff);
		printf("R_POS = %ld\n", cbuff->r_pos);
		printf("W_POS = %ld\n", cbuff->w_pos);
		printf("OVERWRITE = %ld\n", cbuff->overwrite);
		if (c % 9 == 0 && c != 0)
		{
			cbuff_dequeue(cbuff, 128);
			printf("====>DEQUEUE BUFFER       : %s\n", cbuff->dequeue_buff);
			printf("APRES DEQUEUE BUFFER : %s\n", cbuff->buff);
			printf("R_POS = %ld\n", cbuff->r_pos);
			printf("W_POS = %ld\n", cbuff->w_pos);
			printf("OVERWRITE = %ld\n", cbuff->overwrite);
		}
		c++;
	}
	c = 1;
	cbuff_destroy(&cbuff);
	if ((cbuff = cbuff_create(40)) == NULL)
	{
		printf("FAILED TO INIT !\n");
		return (0);
	}
	printf("============================TEST 3=========================\n");
	while (c < 100)
	{
		ft_memcpy(cbuff->enqueue_buff, test_2, ft_strlen(test_2));
		printf("         INIT BUFFER : %s\n", cbuff->buff);
		printf("R_POS = %ld\n", cbuff->r_pos);
		printf("W_POS = %ld\n", cbuff->w_pos);	
		printf("OVERWRITE = %ld\n", cbuff->overwrite);
		cbuff_enqueue(cbuff, ft_strlen(test_2));
		printf("APRES ENQUEUE BUFFER : %s\n", cbuff->buff);
		printf("R_POS = %ld\n", cbuff->r_pos);
		printf("W_POS = %ld\n", cbuff->w_pos);
		printf("OVERWRITE = %ld\n", cbuff->overwrite);
		if (c % 4 == 0 && c != 0)
		{
			cbuff_dequeue(cbuff, 128);
			printf("====>DEQUEUE BUFFER       : %s\n", cbuff->dequeue_buff);
			printf("APRES DEQUEUE BUFFER : %s\n", cbuff->buff);
			printf("R_POS = %ld\n", cbuff->r_pos);
			printf("W_POS = %ld\n", cbuff->w_pos);
			printf("OVERWRITE = %ld\n", cbuff->overwrite);
		}
		c++;
	}
	c = 1;
	cbuff_destroy(&cbuff);
	if ((cbuff = cbuff_create(40)) == NULL)
	{
		printf("FAILED TO INIT !\n");
		return (0);
	}
	printf("============================TEST 4=========================\n");
	while (c < 100)
	{
		ft_memcpy(cbuff->enqueue_buff, test_2, ft_strlen(test_2));
		printf("         INIT BUFFER : %s\n", cbuff->buff);
		printf("R_POS = %ld\n", cbuff->r_pos);
		printf("W_POS = %ld\n", cbuff->w_pos);	
		printf("OVERWRITE = %ld\n", cbuff->overwrite);
		cbuff_enqueue(cbuff, ft_strlen(test_2));
		printf("APRES ENQUEUE BUFFER : %s\n", cbuff->buff);
		printf("R_POS = %ld\n", cbuff->r_pos);
		printf("W_POS = %ld\n", cbuff->w_pos);
		printf("OVERWRITE = %ld\n", cbuff->overwrite);
		cbuff_dequeue(cbuff, 5);
		printf("====>DEQUEUE BUFFER       : %s\n", cbuff->dequeue_buff);
		printf("APRES DEQUEUE BUFFER : %s\n", cbuff->buff);
		printf("R_POS = %ld\n", cbuff->r_pos);
		printf("W_POS = %ld\n", cbuff->w_pos);
		printf("OVERWRITE = %ld\n", cbuff->overwrite);
		c++;
	}
	cbuff_destroy(&cbuff);
	return (0);
}
