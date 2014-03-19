#include <iostream>

using namespace std;

int main()
{
    cout << sizeof(long long) << endl;
    const long long target = 600851475143;
    long long largestPrime = 0;
    bool isPrime;
    for(long long i = 3; i < target/2; i++) {
        isPrime = true;
        cout << "on " << i << endl;
        // if the target is divisble by i...
        if(target % i == 0) {
            // check value for primality
            for(long long j = 2; j < i/2; j++) {
                if(i % j == 0) {
                    isPrime = false;
                    break;
                }
            }
            if(isPrime && i > largestPrime) {
                largestPrime = i;
                cout << "\t\tNew largest prime is " << largestPrime << endl;
            }
        }
    }
    cout << largestPrime << endl;
    return 0;
}
