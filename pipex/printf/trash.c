/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamraou <ylamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:49:25 by ylamraou          #+#    #+#             */
/*   Updated: 2022/03/23 18:55:35 by ylamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdarg.h>
# include <unistd.h>

void	ft_putchar_fd(char c, int *ret)
{
	write(1, &c, 1);
	*ret += 1;
}

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

void	chek(const char *str, va_list arg, int *ret)
{
	if (*str == 's')
		ft_putstr_fd(va_arg(arg, char *), ret);
	ft_putstr_fd(va_arg(arg, char *), ret);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		i;
	int		ret;

	ret = 0;
	i = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
			chek(&str[++i], arg, &ret);
		else
			ft_putchar_fd(str[i], &ret);
		i++;
	}
	va_end(arg);
	return (ret);
}
