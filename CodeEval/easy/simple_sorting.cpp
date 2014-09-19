#include <cstdio>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

int main(int argc, char *argv[])
{
    std::ifstream file;
    std::string lineBuffer;

    file.open(argv[1]);

    while (!file.eof()) {

        getline(file, lineBuffer);

        if (lineBuffer == "") {
            continue;
        } else {
            std::vector<double> numbers;
            std::stringstream ss(lineBuffer);

            do {
                double num = 0.0;
                ss >> num;
                numbers.push_back(num);
            } while (ss.peek() != EOF);

            std::sort(numbers.begin(), numbers.end());

            //std::cout << std::setprecision(5);
            for (int index = 0; index < numbers.size(); index++) {
                if (index == numbers.size() - 1) {
                    printf("%.3f", numbers[index]);
                    //std::cout << numbers[index];
                } else {
                    printf("%.3f ", numbers[index]);
                    //std::cout << numbers[index] << ' ';
                }
            }
        }
        if (!file.eof()) {
            std::cout << std::endl;
        }
    }

    return 0;
}
