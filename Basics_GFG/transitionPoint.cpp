/* Problem: Find Transition Point
Link: https://www.geeksforgeeks.org/problems/find-transition-point-1587115620/1
Approach: Binary Search (Optimal)
Time Complexity: O(log N)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int transitionPoint(vector<int>& arr) {
        int n = arr.size();
        int low = 0, high = n - 1;
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == 1) {
                ans = mid;      // Candidate found, but check for an earlier one
                high = mid - 1; 
            } else {
                low = mid + 1;  // Look in the right half
            }
        }
        return ans;
    }
};

int main() {
    Solution ob;
    vector<int> arr = {0, 0, 0, 1, 1};
    
    int point = ob.transitionPoint(arr);
    cout << "Transition Point (Optimized): " << point << endl;

    return 0;
}