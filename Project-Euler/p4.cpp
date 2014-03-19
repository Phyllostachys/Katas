#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main()
{
//    bool foundIt = false;
    char productStr[6];
    int largestPalindrome = 0;
//    unsigned char thingie = 0x0;

    for(int first = 999; first > 1; first--) {
        for(int second = 999; second > 1; second--) {
            int prod = first * second;
            sprintf(productStr, "%i", prod);
            if(productStr[0]==productStr[5] && productStr[1]==productStr[4] && productStr[2] == productStr[3]) {
                if( prod > largestPalindrome) {
                    largestPalindrome = first*second;
                    cout << largestPalindrome << endl;
                }
            }
        }
    }
//    unsigned int first = 99;
//    unsigned int second = 99;
//    while(!foundIt && first > 0 && second > 0) {
//        int prod = first * second;
//        cout << first << " * " << second << " = " << prod << "\t";
//        sprintf(productStr, "%i", prod);
//        cout << productStr << endl;
////        if(productStr[0]==productStr[5] &&
////                productStr[1]==productStr[4] &&
////                productStr[2]==productStr[3]) {
////            foundIt = true;
////            cout << productStr << endl;
////        }
//        if(productStr[0]==productStr[3] &&
//                productStr[1]==productStr[2]) {
//            foundIt = true;
//            cout << productStr << endl;
//        }
//
//        if(thingie == 0x0) {
//            first --;
//            thingie = (thingie + 1) % 2;
//        } else  {
//            second--;
//            thingie = (thingie + 1) % 2;
//        }
//    }
    cin.ignore();
    cin.get();
    return 0;
}
