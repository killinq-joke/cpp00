/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztouzri <ztouzri@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 17:21:19 by ztouzri           #+#    #+#             */
/*   Updated: 2021/07/01 10:44:08by ztouzri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <iostream>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	int	i;
	int	j;
	int	lastspace;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	lastspace = -1;
	j = i;
	while (j < ft_strlen(str))
	{
		if (str[j] == ' ')
		{
			lastspace = j;
			while (str[j] == ' ')
				j++;
		}
		else
			lastspace = -1;
		j++;
	}
	while (str[i] && i != lastspace)
		write(1, &str[i++], 1);
}

bool	ft_otherisin(char *str, char c)
{
	int	i;

	i = 0;
	while (i < ft_strlen(str))
	{
		if (str[i] != c)
			return (true);
		i++;
	}
	return (false);
}

char	*strtoupper(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 97 && str[i] <= 122)
			str[i] -= 32;
		i++;
	}
	return (str);
}

int	main(int ac, char **av)
{
	int		i;
	char	basestr[] = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";

	if (ac < 2)
		std::cout << basestr << std::endl;
	else
	{
		i = 1;
		while (i < ac)
		{
			ft_putstr(strtoupper(av[i]));
			if (i < ac - 1 && ft_otherisin(av[i + 1], ' '))
				write(1, " ", 1);
			i++;
		}
		std::cout << std::endl;
	}
	return (0);
}
