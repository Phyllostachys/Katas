#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main(int argc, char** argv)
{
    char c;
    std::string buffer;
    std::vector<std::string> words;

    std::ifstream ifs;
    ifs.open(argv[1]);

    while(ifs >> c) {
		int nextChar = ifs.peek();
        if (nextChar != 0x20 && nextChar != 0xA && nextChar != 0xD) {
            buffer += c;
        } else {
			buffer += c;
            words.push_back(buffer);
            buffer.clear();
            if (nextChar == 0xA || nextChar == 0xD) {
				words.pop_back();
                std::cout << words.back() << std::endl;
                words.clear();
            }
        }
    }
}
