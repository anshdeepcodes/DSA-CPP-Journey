/* Problem: Find Transition Point
Link: https://www.geeksforgeeks.org/problems/find-transition-point-1587115620/1
Approach: Linear Search (O(N))
Note: Can be optimized to O(log N) using Binary Search
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int transitionPoint(vector<int>& arr) {
        int n = arr.size();
        
        for (int i = 0; i < n; i++) {
            if (arr[i] == 1) {
                return i;
            }
        }
        
        // if array has no 1
        return -1;
    }
};

int main() {
    Solution ob;
    vector<int> arr = {0, 0, 0, 1, 1};
    
    int point = ob.transitionPoint(arr);
    cout << "Transition Point: " << point << endl;

    return 0;
}