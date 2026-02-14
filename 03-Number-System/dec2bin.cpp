#include <iostream>
using namespace std;

// Function to convert Decimal number to Binary
int dec2bin (int decNum) {
    int binNum = 0;
    int pow = 1; // Used to place remainders in 1s, 10s, 100s place...

    while (decNum > 0) {
        int rem = decNum % 2;  // Get remainder (0 or 1)
        decNum /= 2;           // Divide number by 2
        binNum += rem * pow;   // Form the binary number
        pow *= 10;             // Move to the next power of 10
    }
    return binNum;
}

int main(){
    int num = 10; // Upper limit
    
    // Loop to print binary of numbers from 1 to 10
    for (int i = 1; i <= num; i++) {
        cout << "Binary of " << i << " is " << dec2bin(i) << endl;
    }
    
    return 0;
}