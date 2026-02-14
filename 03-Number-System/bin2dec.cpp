#include <iostream>
using namespace std;

// Function to convert Binary to Decimal
int bin2dec (int binNum) {
    int decNum = 0, pow = 1;

    // Logic: Multiply each digit by powers of 2 (2^0, 2^1, 2^2...)
    while ( binNum > 0) {
        int rem = binNum % 10;  // Get the last digit (0 or 1)
        binNum /= 10;           // Remove the last digit
        decNum += rem * pow;    // Add digit * 2^n to result
        pow *= 2;               // Update power of 2
    }
    return decNum;
}

int main(){
    int binaryNum = 10001;
    
    // Display the conversion result
    cout << "Decimal of " << binaryNum << " is " << bin2dec (binaryNum) << endl;
    
    return 0;
}