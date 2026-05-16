/* Problem: Prefix Sum Array
Link: https://www.geeksforgeeks.org/problems/1-d-prefix-sum/1?
Approach: Iterative Cumulative Sum
Time Complexity: O(N)
Space Complexity: O(N) for storing the prefix array
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> prefSum(vector<int> &arr) {
        int n = arr.size();
        if (n == 0) return {};
    
        vector<int> prefixSum(n);
        
        // Base case: first element remains the same
        prefixSum[0] = arr[0];
    
        // Accumulate sum from left to right
        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + arr[i];
        }
    
        return prefixSum;
    }
};

int main() {
    Solution ob;
    vector<int> arr = {10, 20, 10, 5, 15};
    
    vector<int> res = ob.prefSum(arr);
    
    cout << "Prefix Sum Array: ";
    for (int x : res) cout << x << " ";
    cout << endl;

    return 0;
}