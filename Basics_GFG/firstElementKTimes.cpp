/* Problem: First Element to Occur K Times
Platform: GeeksforGeeks (GFG - Easy)
Approach: Frequency Map + Two Pass Traversal
Time Complexity: O(N) - Count frequencies + find first matching element
Space Complexity: O(N) - Frequency map
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    int firstElement(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        
        // Populate frequencies of all elements
        for (int element : arr) {
            mp[element]++;
        }
        
        // Traverse the array to find the first element with frequency k
        for (int element : arr) {
            if (mp[element] == k) {
                return element; // First element with frequency k
            }
        }
        
        return -1; // Return -1 if no element matches the condition
    }
};

int main() {
    Solution s;
    vector<int> arr = {1, 7, 4, 3, 4, 8, 7};
    int k = 2;
    
    int result = s.firstElement(arr, k);
    cout << "First element occurring " << k << " times is: " << result << endl; // Output: 4
    
    return 0;
}