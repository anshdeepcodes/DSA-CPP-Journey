/* Problem: Permutations in Array (Permute two arrays such that sum of every pair is >= k)
Link: https://www.geeksforgeeks.org/problems/permutations-in-array1747/1
Approach: Greedy Approach using Sorting (Ascending + Descending)
Time Complexity: O(N log N) due to sorting
Space Complexity: O(1) if we don't count the internal sorting space
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    bool isPossible(int k, vector<int> &arr1, vector<int> &arr2) {
        int n = arr1.size();
    
        // Sort arr1 in ascending order
        sort(arr1.begin(), arr1.end());
        
        // Sort arr2 in descending order
        sort(arr2.begin(), arr2.end(), greater<int>());
        
        // Check if any pair sum is less than k
        for (int i = 0; i < n; i++) {
            if (arr1[i] + arr2[i] < k) {
                return false;
            }
        }
        
        return true;
    }
};

int main() {
    Solution ob;
    vector<int> arr1 = {2, 1, 3};
    vector<int> arr2 = {7, 8, 9};
    int k = 10;
    
    if (ob.isPossible(k, arr1, arr2)) {
        cout << "True: Pairs can be formed such that sum >= " << k << endl;
    } else {
        cout << "False: Pairs cannot be formed" << endl;
    }

    return 0;
}