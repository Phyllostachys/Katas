#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int mod(int n, int m);

int main(int argc, char** argv) {
  ifstream file;
  string lineBuffer;
  int n, m;

  file.open(argv[1]);

  while (!file.eof()) {
    getline(file, lineBuffer);

    if (lineBuffer.length() == 0) {
      continue; //ignore all empty lines
    } else {
      string oneAtTime;
      stringstream ss(lineBuffer);
      
      //cout << lineBuffer << endl;
      
      // get n
      getline(ss, oneAtTime, ',');
      stringstream(oneAtTime) >> n;
      
      //get m
      getline(ss, oneAtTime, ',');
      stringstream(oneAtTime) >> m;
      
      //cout << n << " " << m << endl;
      cout << mod(n, m) << endl;
    }
  }
}

int mod(int n, int m) {
  while(n > m) {
    n -= m;
  }
  if(n == m) return 0;
  return n;
}