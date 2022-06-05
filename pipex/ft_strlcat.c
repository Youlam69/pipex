/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamraou <ylamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 01:29:16 by ylamraou          #+#    #+#             */
/*   Updated: 2022/05/26 14:28:28 by ylamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	
	
	size_t	i;
	size_t	lendst;

	if (!src)
		return (size);
	i = -1;
	lendst = ft_strlen(dst);
	while (src[++i])
		dst[lendst + i] = src[i];
	dst[lendst + i] = '\0';
	return (size);
	
	// size_t	i;
	// size_t	lendst;
	// size_t	lensrc;

	// i = 0;
	// lendst = ft_strlen(dst);
	// lensrc = ft_strlen(src);
	// 	printf("|hada hd_cntnt waaast|%s|\n", "hd_ddddddddt");
	// fflush(stdout);
	// if (size < lendst)
	// 	return (size + lensrc);
	// while (*src && (lendst + i + 1) < size)
	// 	dst[lendst + i++] = *src++;
	// dst[lendst + i] = '\0';
	// return (lendst + lensrc);
}
