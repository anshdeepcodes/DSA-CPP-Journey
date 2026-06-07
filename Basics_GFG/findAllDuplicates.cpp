/* Problem: Find All Duplicates in an Array
Platform: GeeksforGeeks / LeetCode 442
Link: https://www.geeksforgeeks.org/problems/find-duplicates-in-an-array/1
Approach: In-place Negative Index Marking (Optimal)
Time Complexity: O(N)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
  public:
    vector<int> findDuplicates(vector<int>& arr) {
        vector<int> ans;
        int n = arr.size();
        
        for (int i = 0; i < n; i++) {
            // Map element value to a valid 0-indexed array position
            int index = abs(arr[i]) - 1;
            
            // If the value at mapped index is negative, it's a duplicate
            if (arr[index] < 0) {
                ans.push_back(abs(arr[i]));
            } 
            // Mark the element as visited by negating its value
            else {
                arr[index] = -arr[index];
            }
        }
        
        return ans;  
    }
};

int main() {
    Solution s;
    vector<int> arr = {4, 3, 2, 7, 8, 2, 3, 1};
    
    vector<int> duplicates = s.findDuplicates(arr);
    
    cout << "Duplicate elements: ";
    for (int x : duplicates) {
        cout << x << " ";
    }
    cout << endl; // Output: 2 3
    
    return 0;
}