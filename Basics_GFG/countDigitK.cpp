/* Problem: Count Digit K in an Array
Link: https://www.geeksforgeeks.org/problems/find-number-of-numbers/1
Approach: Iterative Digit Extraction via Modulo and Division 
Time Complexity: O(N * D)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countDigitK(int k, vector<int>& arr) {
        int count = 0;

        for (int num : arr) {
            // Check each digit of the current number
            while (num > 0) {
                // If the last digit matches k, increment count
                if (num % 10 == k) {
                    count++;
                }
                // Remove the last digit
                num /= 10;
            }
        }

        return count;
    }
};

int main() {
    Solution s;
    vector<int> arr = {11, 12, 21, 31, 41};
    int k = 1;

    int total_occurrences = s.countDigitK(k, arr);
    cout << "Total occurrences of digit " << k << " is: " << total_occurrences << endl; 

    return 0;
}