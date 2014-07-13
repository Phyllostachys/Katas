#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <vector>

int main(int argc, char** argv)
{
    std::string line;
    std::ifstream file(argv[1]);
    if (file.is_open())
    {
        file >> line;
        do
        {
            std::vector<int> numbers;
            for (int index = 0; index < line.length(); index++)
            {
                unsigned int repre = (unsigned int)line[index];
                if (repre >= 'a' && repre <= 'j')
                    numbers.push_back(repre - 97);
                else if (repre >= '0' && repre <= '9')
                    numbers.push_back(repre - 48);
            }
            
            if (numbers.size() == 0) std::cout << "NONE";
            else
            {
                for (int i = 0; i < numbers.size(); i++)
                {
                    std::cout << numbers[i];
                }
            }

            std::cout << std::endl;
            file >> line;
        } while(!file.eof());
    }
    file.close();
    return 0;
}
