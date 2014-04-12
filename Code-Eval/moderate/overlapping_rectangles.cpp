#include <cstdio>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

struct rectangle {
    int x1;
    int y1;
    int x2;
    int y2;
};

std::string checkOverlapping(rectangle r1, rectangle r2);

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
            // ready line for parsing
            for (int index = 0; index < lineBuffer.length(); index++) {
                //std::cout << lineBuffer[index];
                if (lineBuffer[index] == ',') {
                    lineBuffer[index] = ' ';
                }
            }
            //std::cout << std::endl;

            rectangle rect1;
            rectangle rect2;
            std::string number;
            std::stringstream ss(lineBuffer);

            // parse data into data structure
            ss >> rect1.x1 >> rect1.y1 >> rect1.x2 >> rect1.y2;
            ss >> rect2.x1 >> rect2.y1 >> rect2.x2 >> rect2.y2;

            //std::cout << "Rect 1: " << rect1.x1 << "," << rect1.y1 << " " << rect1.x2 << "," << rect1.y2 << std::endl;
            //std::cout << "Rect 2: " << rect2.x1 << "," << rect2.y1 << " " << rect2.x2 << "," << rect2.y2 << std::endl;

            int minXVal, minYVal;

            minXVal = rect1.x1;
            minXVal = rect1.x2 < minXVal ? rect1.x2 : minXVal;
            minXVal = rect2.x1 < minXVal ? rect2.x1 : minXVal;
            minXVal = rect2.x2 < minXVal ? rect2.x2 : minXVal;

            minYVal = rect1.y1;
            minYVal = rect1.y2 < minYVal ? rect1.y2 : minYVal;
            minYVal = rect2.y1 < minYVal ? rect2.y1 : minYVal;
            minYVal = rect2.y2 < minYVal ? rect2.y2 : minYVal;

            minXVal = minXVal < 0 ? minXVal * -1 : minXVal;
            minYVal = minYVal < 0 ? minYVal * -1 : minYVal;

            //std::cout << "Min vals: " << minXVal << " " << minYVal << std::endl;

            rect1.x1 += minXVal;
            rect1.y1 += minYVal;
            rect1.x2 += minXVal;
            rect1.y2 += minYVal;

            rect2.x1 += minXVal;
            rect2.y1 += minYVal;
            rect2.x2 += minXVal;
            rect2.y2 += minYVal;

            // check data and print result
            std::cout << checkOverlapping(rect1, rect2) << std::endl;
        }
        //if (!file.eof()) {
        //    std::cout << std::endl;
        //}
    }

    return 0;
}

std::string checkOverlapping(rectangle r1, rectangle r2)
{
    if (r1.x1 > r2.x1) {
        rectangle temp = r1;
        r1 = r2;
        r2 = temp;
    }

    if ((r2.y1 < r1.y2) || /* r2 is below r1 */
        (r2.x1 > r1.x2) || /* r2 is to the right of r1 */
        (r2.y2 > r1.y1)) { /* r2 is above and right of r1 */
        return "False";
    } else {
        return "True";
    }
}
