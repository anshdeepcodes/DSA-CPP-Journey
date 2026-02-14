#include <iostream>
using namespace std;

int main() {
    int a = 4;
    int b = 8;

    /*
        Bitwise operators work at binary level.
        a = 4  -> 0100
        b = 8  -> 1000
    */

    // Bitwise AND: 1 only when both bits are 1
    cout << (a & b) << endl;

    // Bitwise OR: 1 if any one bit is 1
    cout << (a | b) << endl;

    /*
        Bitwise XOR:
        - Returns 1 when bits are different
        - Returns 0 when bits are same
    */
    cout << (a ^ b) << endl;

    /*
        Left shift operator:
        Shifts bits to the left
        Effectively multiplies the number by 2
    */
    cout << (a << 1) << endl;

    /*
        Right shift operator:
        Shifts bits to the right
        Effectively divides the number by 2
    */
    cout << (b >> 1) << endl;

    return 0;
}
