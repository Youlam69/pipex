/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prnthex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamraou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:50:50 by ylamraou          #+#    #+#             */
/*   Updated: 2022/02/15 20:50:52 by ylamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	prinminithex(unsigned long int nbr, char x, int *ret)
{
	if (x == 'x')
		ft_putchar_fd(TAB[nbr], ret);
	else
	{
		if (nbr >= 10 && nbr < 16)
			ft_putchar_fd(TAB[nbr] - 32, ret);
		else
			ft_putchar_fd(TAB[nbr], ret);
	}
}

void	prnthex(unsigned long int nbr, char x, int *ret)
{
	if (nbr < 16)
		prinminithex(nbr, x, ret);
	if (nbr >= 16)
	{
		prnthex(nbr / 16, x, ret);
		if (x == 'x')
			ft_putchar_fd(TAB[nbr % 16], ret);
		else
		{
			if (nbr % 16 >= 10 && nbr % 16 < 16)
				ft_putchar_fd(TAB[nbr % 16] - 32, ret);
			else
				ft_putchar_fd(TAB[nbr % 16], ret);
		}
	}
}
