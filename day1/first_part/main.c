/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahommer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 08:12:10 by bahommer          #+#    #+#             */
/*   Updated: 2023/12/03 08:45:47 by bahommer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fcntl.h>
#include "./libft/inc/libft.h"

int	get_digit(char *str)
{
	int	i;
	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
				break ;
		i++;	
	}
	if (i == (int)ft_strlen(str))
		return 0;

	int	j = ft_strlen(str) - 1;
	while (j > 0)
	{
		if (ft_isdigit(str[j]))
			break;
		j--;
	}
	return (((str[i] - 48) * 10) + str[j] - 48);
}

int	main(int ac, char **av)
{
	(void)ac;
	int	number;
	int	digit;
	int	fd;
	fd = open(av[1], O_RDONLY);

	char *str;
	str = get_next_line(fd);
	number = 0;
	while (str)
	{
		digit = get_digit(str);
		number += digit;
		printf("%i, %i\n", digit, number);
		str = get_next_line(fd);
	}
	printf("FINAL ANSWER %i\n", number);
	return 0;
}
