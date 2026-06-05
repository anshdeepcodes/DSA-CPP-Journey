/* Problem: Painter's Partition Problem
Course: Apna College DSA (Shradha Didi)
Approach: Binary Search on Answer Space (O(N * log(sum - max)))
Time Complexity: O(N * log(sum))
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    // Helper function to check if the max time limit is valid
    bool isValid(vector<int>& arr, int n, int m, int maxAllowedTime) {
        int painters = 1, cardboard = 0;
        
        for (int i = 0; i < n; i++) {
            // If a single cardboard exceeds limit, configuration fails
            if (arr[i] > maxAllowedTime) return false;
            
            // Allocate cardboard to the current painter
            if (cardboard + arr[i] <= maxAllowedTime) {
                cardboard += arr[i];
            } else {
                // Move to the next painter
                painters++;
                cardboard = arr[i];
            }
        }
        
        // Return true if painters required don't exceed given m
        return painters > m ? false : true;
    }

  public:
    int findMinimumTime(vector<int> &arr, int m) {
        int n = arr.size();
        
        int sum = 0, maxVal = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            maxVal = max(maxVal, arr[i]);
        }
        
        // Range: st is the largest cardboard, end is the total sum of painting time
        int st = maxVal, end = sum;
        int ans = -1;
        
        // Binary Search on answer range
        while (st <= end) {
            int mid = st + (end - st) / 2;
            
            if (isValid(arr, n, m, mid)) {
                ans = mid;        // Potential answer found
                end = mid - 1;    // Try for a smaller maximum
            } else {
                st = mid + 1;     // Increase the limit
            }
        }
        
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> arr = {5, 6, 9, 2, 19};
    int m = 2; // Number of painters
    
    cout << "Minimum time for painting cardboard: " << s.findMinimumTime(arr, m) << endl; // Output: 21
    return 0;
}