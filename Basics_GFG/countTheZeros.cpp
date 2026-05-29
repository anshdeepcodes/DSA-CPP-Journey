/* Problem: Count the Zeros
Link: https://www.geeksforgeeks.org/problems/count-the-zeros2550--141153/1
Approach: Binary Search to find the first occurrence of 0 (Optimal)
Time Complexity: O(log N) - Logarithmic time as search space halves
Space Complexity: O(1) - Constant auxiliary space
*/

#include <iostream>
using namespace std;

class Solution {
  public:
    int countZeroes(int arr[], int n) {
        int low = 0;
        int high = n - 1;
        int firstZeroIndex = -1; // Tracks the starting position of 0s
        
        // Binary Search Loop
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            // If 0 is found, it could be the first one, or there could be more to the left
            if (arr[mid] == 0) {
                firstZeroIndex = mid;
                high = mid - 1; // Move left to find the first absolute zero
            } 
            // If it's a 1, since array is sorted as 1s then 0s, look into the right half
            else {
                low = mid + 1;
            }
        }
        
        // Edge Case: If no zero was found in the entire array
        if (firstZeroIndex == -1) {
            return 0;
        }
        
        // Total elements minus the first zero's index gives the total count of zeros
        return n - firstZeroIndex;
    }
};

int main() {
    Solution s;
    
    // Test Case 1: Mixed 1s and 0s
    int arr1[] = {1, 1, 1, 1, 1, 0, 0, 0};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << "Count of Zeros (Test Case 1): " << s.countZeroes(arr1, n1) << endl; // Output: 3

    // Test Case 2: All 1s (No zeros)
    int arr2[] = {1, 1, 1, 1};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << "Count of Zeros (Test Case 2): " << s.countZeroes(arr2, n2) << endl; // Output: 0

    return 0;
}