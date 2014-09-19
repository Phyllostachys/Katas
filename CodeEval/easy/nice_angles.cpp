#include <cstdint>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>

int main(int argc, char** argv)
{
	std::ifstream ifs(argv[1]);
	double num;

	while (ifs >> num) {
		std::cout << floor(num) << ".";
		num -= floor(num);
		std::cout << std::setfill('0') << std::setw(2);
		std::cout << floor(60 * num) << "\'";
		num = (num * 60) - floor(60 * num);
		std::cout << std::setfill('0') << std::setw(2);
		std::cout << floor(60 * num) << "\"";
		std::cout << std::endl;
	}
	ifs.close();
	return 0;
}