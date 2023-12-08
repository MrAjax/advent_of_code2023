#include <iostream>
#include <string>
#include <fstream>

bool	isPossible(std::string str) {
	
//	int	red = 12;
//	int	green = 13;
//	int	blue = 14;
	
	size_t start = str.find(":");
	std::string temp = str.substr(start);
	size_t end  = 0;;
	while (end != std::string::npos) {
		int red_temp = 0;
	//	int	blue_temp = 0;
	//	int	green_temp = 0;
		end = temp.find(";");
		if (temp.find("red") < end) {
			red_temp = stoi(temp.substr(temp.find("red") - 3));
			std::cout << "RED = " << red_temp << " ";
		}	
		start = end + 1;
		temp = str.substr(start);
		std::cout << "[" << temp << "]" << std::endl;
	}	
	return true;
}		


int	main()
{
	std::ifstream ifs;

	ifs.open("input", std::ifstream::in);
	std::string str;
	int	total = 0;
	int	Game = 1;
	while (getline(ifs, str))
	{
		if (isPossible(str))
			total += Game;
		Game++;
	}
	std::cout << "FINAL ANSWER" << total << std::endl;
}
