/* 
Problem: Arrange the array (arr[i] >= arr[i-1] for odd i)
Link: https://www.geeksforgeeks.org/problems/play-with-an-array/1
Approach: Greedy Swap (Iterative)
Time Complexity: O(N)
Space Complexity: O(1) 
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    bool formatArray(vector<int> &arr) {
        int n = arr.size();
        // Traverse only odd indices
        for (int i = 1; i < n; i += 2) {
            // If element at odd index is smaller than previous
            if (arr[i] < arr[i - 1]) {
                swap(arr[i], arr[i - 1]);
            }
        }
        // Note: The logic ensures arr[1]>=arr[0], arr[3]>=arr[2], etc.
        return true; 
    }
};

int main() {
    Solution ob;
    vector<int> arr = {10, 5, 6, 3, 2, 20};
    
    if (ob.formatArray(arr)) {
        cout << "Formatted Array: ";
        for (int x : arr) cout << x << " ";
        cout << endl;
    } else {
        cout << "Not possible to format." << endl;
    }

    return 0;
}