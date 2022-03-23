/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamraou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:49:39 by ylamraou          #+#    #+#             */
/*   Updated: 2022/02/15 20:49:41 by ylamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_fd(int n, int *ret)
{
	long int	nbr;

	nbr = n;
	if (nbr < 0)
	{
		nbr *= -1;
		ft_putchar_fd('-', ret);
	}
	if (nbr > 9)
	{
		ft_putnbr_fd(nbr / 10, ret);
		ft_putnbr_fd(nbr % 10, ret);
	}
	else
		ft_putchar_fd(nbr + 48, ret);
}
