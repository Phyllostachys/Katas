#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

int main(int argc, char** argv)
{
	std::ifstream ifs;
	ifs.open(argv[1]);
	if (!ifs.is_open()) { return 1; }

	bool done = false;
	while (!done) {
		bool pipeYet = false;
		std::string encStr;
		std::string strBuf;
		std::vector<int> encryption;
		
		// get the encoded string
		getline(ifs, encStr, '|');
		getline(ifs, strBuf);

		std::stringstream ss(strBuf);

		int num;
		while (ss >> num) {
			std::cout << encStr[num - 1];
		}

		std::cout << std::endl;
		if (ifs.eof()) {
			done = true;
		}
	}

	ifs.close();
	return 0;
}