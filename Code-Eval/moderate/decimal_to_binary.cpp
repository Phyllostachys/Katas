#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <string>

using namespace std;

string decToBin(int n);

int main(int argc, char** argv) {
  ifstream file;
  string lineBuffer;
  int n = 0;

  file.open(argv[1]);

  while (!file.eof()) {
    getline(file, lineBuffer);

    if (lineBuffer.length() == 0) {
      continue; //ignore all empty lines
    } else {
    stringstream ss(lineBuffer);
      ss >> n;
      //cout << n <<  " ";
      cout << decToBin(n) << endl;
    }
  }
}

string decToBin(int n) {
  string res = "";
  int index = 0;

  while(n > 0) {
    if(n & 0x1 == 0x1) {
        res = "1" + res;
    }
    else {
        res = "0" + res;
    }
    n >>= 1;
  }
  return res;
}