#include <cstdint>
#include <iostream>
#include <string>
#include <fstream>

std::string rotate(std::string str)
{
    std::string result;
    result += str[str.length() - 1];
    result += str.substr(0, str.length() - 1);
    return result;
}


bool isRotated(std::string key, std::string test)
{
    if (key.length() == test.length()) {
        std::string tempStr = key;
        for (uint32_t i = 0; i < key.length(); i++) {
            tempStr = rotate(tempStr);
            if (tempStr.compare(test) == 0) { return true; }
        }
        return false;
    } else if (key.length() > test.length()) {
        return false;
    } else {
        uint32_t sizeDiff = test.length() - key.length();
        std::string tempStr = key;
        for (uint32_t offset = 0; offset < sizeDiff; offset++) {
            for (uint32_t i = 0; i < key.length(); i++) {
                tempStr = rotate(tempStr);
                if (test.find(tempStr, offset) != std::string::npos) { return true; }
            }
            tempStr = key;
        }
        return false;
    }
}


int main(int argc, char** argv)
{
    std::ifstream ifs(argv[1]);
    std::string key, test;
    uint8_t c;
    bool firstWord = true;
    while (ifs >> c) {
        //std::cout << c;
        if (c == ',') {
            firstWord = false;
            //std::cout << " now on the second word" << std::endl;
        } else if (c != ',') {
            if (ifs.peek() == 0xD || ifs.peek() == 0xA) {
                if (firstWord == true) {
                    key += c;
                } else if (firstWord == false) {
                    test += c;
                }
                //std::cout << " finished a line" << std::endl;
                firstWord = true;
                std::cout << (isRotated(key, test) == true ? "True" : "False") << std::endl;

                // reset state
                key  = "";
                test = "";
            } else {
                if (firstWord == true) {
                    key += c;
                } else if (firstWord == false) {
                    test += c;
                }
            }
        }
    }
    ifs.close();
    return 0;
}
