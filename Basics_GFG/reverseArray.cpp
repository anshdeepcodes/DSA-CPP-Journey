/* Problem: Reverse an Array
Link: https://www.geeksforgeeks.org/problems/reverse-an-array/1
Approach: Two-Pointer In-place Swap
Time Complexity: O(N)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    void reverseArray(vector<int> &arr) {
        int st = 0, end = arr.size() - 1;
        
        // Loop runs until the two pointers meet in the middle
        while (st < end) {
            // Swapping elements at start and end pointers
            int temp = arr[st];
            arr[st] = arr[end];
            arr[end] = temp;
            
            // Move pointers towards each other
            st++;
            end--;
        }
    }
};

int main() {
    Solution s;
    vector<int> arr = {1, 4, 3, 2, 6, 5};
    
    cout << "Original Array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    s.reverseArray(arr);

    cout << "Reversed Array: ";
    for (int x : arr) cout << x << " ";
    cout << endl; // Output: 5 6 2 3 4 1

    return 0;
}