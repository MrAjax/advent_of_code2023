/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahommer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:58:11 by bahommer          #+#    #+#             */
/*   Updated: 2023/12/07 07:45:10 by bahommer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int	first_found(std::string str) {

	size_t	found = std::string::npos;
	size_t	temp;
	int		index = 0;
	std::string tabl[] = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	std::string tabn[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9"};
		for (int i = 0; i < 9; i++) {
			temp = str.find(tabl[i]);
			if (temp <= found) {
				found = temp;
				index = i;
			}	
		
		}
		for (int i = 0; i < 9; i++) {
			temp = str.find(tabn[i]);
			if (temp <= found) {
				found = temp;
				index = i;
			}	
		}	
	return index + 1; 
}

int	last_found(std::string str) {

	size_t	found = 0;
	size_t	temp;
	int		index = 0;
	std::string tabl[] = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	std::string tabn[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9"};
		for (int i = 0; i < 9; i++) {
			temp = str.rfind(tabl[i]);
			if (temp >= found && temp != std::string::npos) {
				found = temp;
				index = i;
			}	
		
		}
		for (int i = 0; i < 9; i++) {
			temp = str.rfind(tabn[i]);
			if (temp >= found && temp != std::string::npos) {
				found = temp;
				index = i;
			}	
		}	
	return index + 1; 
}
int	main()
{

	std::ifstream ifs;

	ifs.open("input", std::ifstream::in);
	std::string str;
	int	total = 0;
	int	temp;
	int	i = 0;
	while (getline(ifs, str))
	{
		i++;
		temp = first_found(str) * 10 + last_found(str);
		total += temp;
		std::cout << temp << ", " << total << std::endl;
	}
	std::cout << "FINAL ANSWER" << total << std::endl;
}
