#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <cctype>
#include <cstddef>

bool	digitIsLegit(size_t found, size_t digit, int i, std::vector<std::string> tab) {

	size_t symbol = 0;
	if (i > 0) {
		if (found == 0) {
			symbol = tab[i - 1].find_first_not_of("012456789.", found); 
		}	
		else {
			symbol = tab[i - 1].find_first_not_of("012456789.", found - 1); 		
		}	
		if (symbol <= found + digit && symbol != std::string::npos)	
			return true;
	}	
	if (found != 0) {
		char prevChar = tab[i][found - 1];
		if (prevChar != '.' && !isdigit(prevChar))
			return true;
	}	
	if (found + digit < tab[i].length() - 1) {
		char nextChar = tab[i][found + digit];
		if (nextChar != '.' && !isdigit(nextChar))
			return true;
	}
	size_t symbol2 = 0;
	if (static_cast<size_t>(i) < tab.size() - 1) {
		if (found == 0)
			symbol2 = tab[i + 1].find_first_not_of("012456789.", found); 
		else
			symbol2 = tab[i + 1].find_first_not_of("012456789.", found - 1); 
		if (symbol2 <= found + digit && symbol2 != std::string::npos)	
			return true;
	}	
	return false;
}

int	lineTotal(std::string & line, int i, std::vector<std::string> tab) {
	
	std::size_t found = line.find_first_of("0123456789");
	int	total = 0;
	while (found != std::string::npos) {
		size_t	digit = line.find_first_not_of("0123456789", found) - found;
		if (digitIsLegit(found, digit, i, tab)) {
			int number = stoi(line.substr(found));
			std::cout << number << std::endl;
			total += number; 
		}	
		found = line.find_first_of("0123456789", found + digit);
	}
		return total;
}
		
int main() {

	std::ifstream ifs;
	std::vector<std::string> tab;
	ifs.open("input.txt", std::ifstream::in);
	std::string str;
	while (getline(ifs, str)) {
		tab.push_back(str);
	}
	
	size_t	i = 0;
	int		total = 0;
	while(i < tab.size()) {
		total += lineTotal(tab[i], i, tab);
		i++;
	}	
	std::cout << "TOTAL = " << total << std::endl;
}	
