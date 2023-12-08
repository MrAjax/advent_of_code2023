#include <iostream>
#include <string>
#include <fstream>

int	CubeTot(std::string& str) {
	
	int	red = 0;
	int	green = 0;
	int	blue = 0;
	
	size_t start = str.find(":");
	std::string temp = str.substr(start);
	size_t end  = 0;;
	while (end != std::string::npos) {
		int red_temp = 0;
		int	blue_temp = 0;
		int	green_temp = 0;
		end = temp.find(";");
		if (temp.find("red") < end) {
			red_temp = stoi(temp.substr(temp.find("red") - 3));
			if (red_temp > red)
				red = red_temp;
		}	
		if (temp.find("green") < end) {
			green_temp = stoi(temp.substr(temp.find("green") - 3));
			if (green_temp > green)
				green = green_temp;
		}	
		if (temp.find("blue") < end) {
			blue_temp = stoi(temp.substr(temp.find("blue") - 3));
			if (blue_temp > blue)
				blue = blue_temp;
		}	
		start = end + 1;
		temp = temp.substr(start);
	}	
	return (green * blue * red);
}		


int	main()
{
	std::ifstream ifs;

	ifs.open("input", std::ifstream::in);
	std::string str;
	int	total = 0;
	while (getline(ifs, str))
	{
		total += CubeTot(str);
	}
	std::cout << "FINAL ANSWER " << total << std::endl;
}
/* PART I
bool	isPossible(std::string str) {
	
	int	red = 12;
	int	green = 13;
	int	blue = 14;
	
	size_t start = str.find(":");
	std::string temp = str.substr(start);
	size_t end  = 0;;
	while (end != std::string::npos) {
		int red_temp = 0;
		int	blue_temp = 0;
		int	green_temp = 0;
		end = temp.find(";");
		if (temp.find("red") < end) {
			red_temp = stoi(temp.substr(temp.find("red") - 3));
		//	std::cout << "RED = " << red_temp << " ";
			if (red_temp > red)
				return false;
		}	
		if (temp.find("green") < end) {
			green_temp = stoi(temp.substr(temp.find("green") - 3));
			if (green_temp > green)
				return false;
		}	
		if (temp.find("blue") < end) {
			blue_temp = stoi(temp.substr(temp.find("blue") - 3));
			if (blue_temp > blue)
				return false;
		}	
		start = end + 1;
		temp = temp.substr(start);
	//	std::cout << "[" << temp << "]" << std::endl;
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
}*/
