/* Problem: Find the smallest and second smallest element in an array
Link: https://www.geeksforgeeks.org/problems/find-the-smallest-and-second-smallest-element-in-an-array3226/1
Approach: Single Pass Iterative (Optimal)
Time Complexity: O(N)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
  public:
    vector<int> minAnd2ndMin(vector<int> &arr) {
        int smallest = INT_MAX;
        int smallest2nd = INT_MAX;

        for (int i = 0; i < arr.size(); i++) {
            // If current element is smaller than smallest
            if (arr[i] < smallest) {
                smallest2nd = smallest;
                smallest = arr[i];
            }
            // If current element is between smallest and smallest2nd
            else if (arr[i] < smallest2nd && arr[i] != smallest) {
                smallest2nd = arr[i];
            }
        }

        // Return -1 if second smallest doesn't exist (e.g., all elements are same)
        return (smallest2nd != INT_MAX)
               ? vector<int>{smallest, smallest2nd}
               : vector<int>{-1};
    }
};

int main() {
    Solution ob;
    vector<int> arr = {12, 13, 1, 10, 34, 1};
    
    vector<int> res = ob.minAnd2ndMin(arr);
    
    cout << "Result: ";
    for (int x : res) cout << x << " ";
    cout << endl;

    return 0;
}