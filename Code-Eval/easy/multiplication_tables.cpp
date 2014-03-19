#include <iostream>
#include <iomanip>

int main() {
    for(int y = 1; y <= 12; y++) {
        for(int x = 1; x <= 12; x++) {
            if(x == 1)
                if(y < 10)
                    std::cout << (x * y);
                else
                    std::cout << std::setw(2) << (x * y);
            else
                std::cout << std::setw(4) << std::right << (x * y);
        }
        std::cout << std::endl;
    }
}