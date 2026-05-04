/* 
Problem: Missing Number
Link: https://www.geeksforgeeks.org/problems/missing-number-in-array1416/1
Approach: XOR (Bit Manipulation)
Time Complexity: O(N)
Space Complexity: O(1) 
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int missingNum(vector<int>& arr) {
        int xor1 = 0, xor2 = 0;
        int n = arr.size() + 1;

        // XORing all elements in array and numbers from 1 to n-1
        for (int i = 0; i < arr.size(); i++) {
            xor1 ^= arr[i];
            xor2 ^= (i + 1);
        }

        // XORing the last number (n)
        xor2 ^= n;

        // Missing number will be the result of xor1 ^ xor2
        return xor1 ^ xor2;
    }
};

int main() {
    Solution ob;
    vector<int> arr = {1, 2, 3, 5}; // Example: n=5, missing=4
    
    cout << "Missing Number: " << ob.missingNum(arr) << endl;

    return 0;
}