/* Problem: Find Missing and Repeating Element
Link: https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1
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
    vector<int> findTwoElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans; // Will store [Repeating, Missing]
        
        // Step 1: Identify the repeating element using negation marking
        for (int i = 0; i < n; i++) {
            int idx = abs(arr[i]) - 1;
            
            // If already negative, this element is a duplicate
            if (arr[idx] < 0) {
                ans.push_back(abs(arr[i]));
            } else {
                arr[idx] = -arr[idx]; // Mark as visited
            }
        }
        
        // Step 2: Identify the missing element by checking positive values
        for (int i = 0; i < n; i++) {
            // The index that remains positive corresponds to the missing number
            if (arr[i] > 0) {
                ans.push_back(i + 1);
            }
        }
        
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> arr = {2, 2, 1, 4, 5}; // 2 is repeating, 3 is missing
    
    vector<int> result = s.findTwoElement(arr);
    
    cout << "Repeating: " << result[0] << ", Missing: " << result[1] << endl; // Output: 2, 3
    
    return 0;
}