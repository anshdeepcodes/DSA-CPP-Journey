/* Problem: Rearrange Array (Even places even, Odd places odd)
Link: https://www.geeksforgeeks.org/problems/even-and-odd/1
Approach: Two-Pointer Approach with Step 2
Time Complexity: O(N)
Space Complexity: O(1)
*/

#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
  public:
    void reArrange(int arr[], int N) {
        int evenIdx = 0; // Pointer for even indices (0, 2, 4, ...)
        int oddIdx = 1;  // Pointer for odd indices (1, 3, 5, ...)
        
        // Loop runs until any one of the pointers goes out of bounds
        while (evenIdx < N && oddIdx < N) {
            // If even index already has an even number, just move to the next even index
            if (arr[evenIdx] % 2 == 0) {
                evenIdx += 2;
            }
            // If odd index already has an odd number, just move to the next odd index
            else if (arr[oddIdx] % 2 != 0) {
                oddIdx += 2;
            }
            // If both are misplaced, swap them to put them in their correct positions
            else {
                swap(arr[evenIdx], arr[oddIdx]);
                evenIdx += 2;
                oddIdx += 2;
            }
        }
    }
};

int main() {
    Solution s;
    int arr[] = {3, 6, 12, 1, 5, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Original Array: ";
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    s.reArrange(arr, n);

    cout << "Rearranged Array: ";
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl; // Output format will satisfy: even indices have even, odd indices have odd

    return 0;
}