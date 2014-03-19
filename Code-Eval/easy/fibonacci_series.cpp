#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <string>

int fib(int n);

using namespace std;

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
      cout << fib(n) << endl;
    }
  }
}

int fib(int n) {
  if(n == 0) return 0;
  else if(n == 1) return 1;
  else return fib(n-1) + fib(n-2);
}
