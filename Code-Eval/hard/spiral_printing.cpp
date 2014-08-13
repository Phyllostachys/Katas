#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <vector>

int main(int argc, char** argv)
{
    int matX = 0, matY = 0;
    std::ifstream ifs(argv[1], std::ios_base::in);

    if (!ifs.good()) { return 1; }
    while (!ifs.eof() || ifs.peek() != EOF) {
        ifs >> matY;
        ifs.ignore();
        ifs >> matX;
        ifs.ignore();
		//std::cout << matX << " " << matY << std::endl;

        std::vector<std::vector<int>> matrix;
        for (int y = 0; y < matY; y++) {
            std::vector<int> tempRow;
            for (int x = 0; x < matX; x++) {
                ifs >> std::ws;
                int num = 0;
                ifs >> num;
				//std::cout << num << " ";
                tempRow.push_back(num);
            }
            matrix.push_back(tempRow);
			//std::cout << std::endl;
        }
		//std::cout << std::endl;

        int counter = matY * matX;
		int determiner = matX % 3 == 0 ? 2 : 1;
        for (int ring = 0; ring < (matX / 2) + 1; ring++) {
            // top edge
            for (int x = ring; x < matX - ring; x++) {
                std::cout << matrix[ring][x] << " ";
                counter--;
                if (counter <= 0) { break; }
            }
            if (counter <= 0) { break; }
            // right edge
            for (int y = ring + 1; y < matY - ring; y++) {
                std::cout << matrix[y][matX - ring - 1] << " ";
                counter--;
                if (counter <= 0) { break; }
            }
            if (counter <= 0) { break; }
            // bottom edge
            for (int x = matX - ring - 2; x >= ring; x--) {
                std::cout << matrix[matY - ring - 1][x] << " ";
                counter--;
                if (counter <= 0) { break; }
            }
            if (counter <= 0) { break; }
            // left edge
            for (int y = matY - ring - 2; y > ring; y--) {
                std::cout << matrix[y][ring] << " ";
                counter--;
                if (counter <= 0) { break; }
            }
            if (counter <= 0) { break; }
        }

        std::cout << std::endl;
		ifs >> std::ws;
		ifs.peek();
	}

    ifs.close();
    return 0;
}
