/* Problem: Numbers Containing Only 1, 2, and 3
Link: https://www.geeksforgeeks.org/problems/numbers-containing-1-2-and-32555/1
Approach: Digit Extraction and Validation (Optimal)
Time Complexity: O(N * K) - Where K is max digits in a number
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    // Helper function to validate if a number contains only 1, 2, or 3
    bool isValid(int val) {
        int temp = val;
        while (temp > 0) {
            int digit = temp % 10;
            // Reject immediately if any digit is outside the allowed set
            if (digit != 1 && digit != 2 && digit != 3) {
                return false;
            }
            temp /= 10;
        }
        return true;
    }

  public:
    vector<int> filterByDigits(vector<int>& arr) {
        vector<int> result;
        
        // Filter elements based on digit validation
        for (int val : arr) {
            if (isValid(val)) {
                result.push_back(val);
            }
        }
        
        // Return -1 if no matching elements are found
        if (result.empty()) {
            return {-1};
        }
        
        return result;
    }
};

int main() {
    Solution s;
    vector<int> arr = {123, 234, 11, 32, 45};
    
    vector<int> matchingNumbers = s.filterByDigits(arr);
    
    cout << "Filtered numbers: ";
    for (int x : matchingNumbers) {
        cout << x << " ";
    }
    cout << endl; // Output: 123 11 32
    
    return 0;
}