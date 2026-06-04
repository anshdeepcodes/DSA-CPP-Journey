/* Problem: Book Allocation Problem
Course: Apna College DSA (Shradha Didi)
Approach: Binary Search on Answer (O(N * log(sum - max)))
Time Complexity: O(N * log(sum)) - Linear check inside log search space
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    // Helper function to check if a configuration is valid
    bool isValid(vector<int>& arr, int n, int m, int maxAllowedPages) {
        int students = 1, pages = 0;
        
        for (int i = 0; i < n; i++) {
            // If a single book exceeds limit, configuration fails
            if (arr[i] > maxAllowedPages) return false;
            
            // Allocate books to the current student
            if (pages + arr[i] <= maxAllowedPages) {
                pages += arr[i];
            } else {
                // Move to the next student
                students++;
                pages = arr[i];
            }
        }
        
        // Return true if students required don't exceed given m
        return students > m ? false : true;
    }

  public:
    int findPages(vector<int> &arr, int m) {
        int n = arr.size();
        if (m > n) return -1; // More students than books is impossible
        
        int sum = 0, maxVal = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            maxVal = max(maxVal, arr[i]);
        }
        
        // Range: st is the largest single book, end is the total sum of pages
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
    vector<int> arr = {12, 34, 67, 90};
    int m = 2; // Number of students
    
    cout << "Minimum of maximum pages: " << s.findPages(arr, m) << endl; // Output: 113
    return 0;
}