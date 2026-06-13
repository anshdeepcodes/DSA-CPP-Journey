/* Problem: Two Non-Repeating Elements (Single Number III)
Platform: GFG / LeetCode(260)
Approach: Bit Manipulation via Rightmost Set Bit Mask (Optimal)
Time Complexity: O(N)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> singleNum(vector<int>& arr) {
        long long xor_sum = 0; // Using long long to prevent signed integer overflow

        // Step 1: XOR all elements to get (x ^ y)
        for (int val : arr) {
            xor_sum ^= val;
        }
        
        // Step 2: Extract the rightmost set bit as a mask
        long long mask = xor_sum & -xor_sum;
        
        int x = 0;
        int y = 0;

        // Step 3: Divide elements into two buckets based on the set bit
        for (int val : arr) {
            if ((mask & val) != 0) {
                x ^= val; // Bucket 1: Bit is set
            } else {
                y ^= val; // Bucket 2: Bit is not set
            }
        }
        
        // Return the unique numbers in ascending order
        if (x < y) return {x, y};            
        else return {y, x};
    }
};

int main() {
    Solution s;
    vector<int> arr = {1, 2, 3, 2, 1, 4}; // 3 and 4 are unique
    
    vector<int> result = s.singleNum(arr);
    
    cout << "The two unique elements are: " << result[0] << " and " << result[1] << endl; // Output: 3 and 4
    
    return 0;
}