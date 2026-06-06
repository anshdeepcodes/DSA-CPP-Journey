/* Problem: Aggressive Cows Problem
Course: Apna College DSA (Shradha Didi)
Approach: Binary Search on Answer Space (O(N * log(max_dist)))
Time Complexity: O(N * log(M)) - Where M = max_stall - min_stall
Space Complexity: O(1) - Constant auxiliary space
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    // Helper to check if cows can be placed with given minimum distance
    bool isPossible(vector<int> &stalls, int n, int c, int minAllowedDistance) {
        int cows = 1;
        int last_positioned_stall = stalls[0]; // Place first cow at first stall

        for (int i = 1; i < n; i++) {           
            // Check if distance between stalls is valid
            if (stalls[i] - last_positioned_stall >= minAllowedDistance) {
                last_positioned_stall = stalls[i]; // Update reference point
                cows++;
            }

            if (cows == c) return true; // All cows safely placed
        }

        return false;
    }

  public:
    int cowDistance(vector<int> &stalls, int c) {
        int n = stalls.size();

        // Handle invalid cow count constraints
        if (c < 2 || c > n) return -1;

        // Sorting mandatory to compute real physical distances
        sort(stalls.begin(), stalls.end());

        // Range: st is min possible distance, end is max possible distance
        int st = 1;
        int end = stalls[n - 1] - stalls[0];
        int distance = -1;

        // Binary Search on answer space
        while (st <= end) {
            int mid = st + (end - st) / 2;

            if (isPossible(stalls, n, c, mid)) {
                distance = mid; // Potential maximized minimum distance found
                st = mid + 1;   // Try to maximize the minimum distance
            } else {
                end = mid - 1;  // Reduce distance limit
            }
        }
        return distance;
    }
};

int main() {
    Solution s;
    vector<int> stalls = {1, 2, 8, 4, 9};
    int cow = 3;

    cout << "Minimum largest distance between 2 cows = " << s.cowDistance(stalls, cow) << endl; // Output: 3
    return 0;
}