/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahommer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 08:12:10 by bahommer          #+#    #+#             */
/*   Updated: 2023/12/03 09:02:30 by bahommer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fcntl.h>
#include "./../libft/inc/libft.h"

int	return_number_in_char(char *str)
{
	if (!ft_strncmp(str, "one", 3))
		return 1;
	else if (!ft_strncmp(str, "two", 3))
		return 2;
	else if (!ft_strncmp(str, "three", 5))
		return 3;
	else if (!ft_strncmp(str, "four", 4))
		return 4;
	else if (!ft_strncmp(str, "five", 4))
		return 5;
	else if (!ft_strncmp(str, "six", 3))
		return 6;
	else if (!ft_strncmp(str, "seven", 5))
		return 7;
	else if (!ft_strncmp(str, "eight", 5))
		return 8;
	else if (!ft_strncmp(str, "nine", 4))
		return 9;
	else
		return 0;
}		

int	get_digit(char *str)
{
	int	i = 0;
	int	j = ft_strlen(str) - 1;
	int	first_digit = 0;
	int	second_digit = 0;
	while (str[i])
	{
		if (return_number_in_char(&str[i]))
		{
			first_digit = return_number_in_char(&str[i]);
			break;
		}
		if (ft_isdigit(str[i]))
			break ;
		i++;
	}
	if (i == (int)ft_strlen(str))
		return 0;

	while (j > 0)
	{
		if (return_number_in_char(&str[j]))
		{
			second_digit = return_number_in_char(&str[j]);
			break;
		}
		if (ft_isdigit(str[j]))
			break;
		j--;
	}
	if (first_digit == 0)
		first_digit = str[i] - 48;
	first_digit *= 10;
	if (second_digit == 0)
		second_digit = str[j] - 48;
	return (first_digit + second_digit);
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
