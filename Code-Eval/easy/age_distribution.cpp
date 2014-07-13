#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

int main(int argc, char** argv)
{
    std::ifstream file;
    std::string lineBuffer;

    file.open(argv[1]);
    while (!file.eof()) {
        getline(file, lineBuffer);
        if (lineBuffer.length() == 0) {
            continue; //ignore all empty lines
        } else {
            int age = atoi(lineBuffer.c_str());
            //std::cout << age << " ";
            if (age >= 0 && age <= 2) {
                std::cout << "Home" << std::endl;
            } else if (age >= 3 && age <= 4) {
                std::cout << "Preschool" << std::endl;
            } else if (age >= 5 && age <= 11) {
                std::cout << "Elementary school" << std::endl;
            } else if (age >= 12 && age <= 14) {
                std::cout << "Middle school" << std::endl;
            } else if (age >= 15 && age <= 18) {
                std::cout << "High school" << std::endl;
            } else if (age >= 19 && age <= 22) {
                std::cout << "College" << std::endl;
            } else if (age >= 23 && age <= 65) {
                std::cout << "Work" << std::endl;
            } else if (age >= 66 && age <= 100) {
                std::cout << "Retirement" << std::endl;
            } else {
                std::cout << "This program is for humans" << std::endl;
            }
        }
    }
}