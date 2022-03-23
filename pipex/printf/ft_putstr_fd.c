/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamraou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:51:17 by ylamraou          #+#    #+#             */
/*   Updated: 2022/02/15 20:51:19 by ylamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_fd(char *s, int *ret)
{
	unsigned int	i;

	i = 0;
	if (!s)
		ft_putstr_fd("(null)", ret);
	else
		while (s[i] != '\0')
			ft_putchar_fd(s[i++], ret);
}
