/* Problem: Check Duplicates in an Array
Link: https://www.geeksforgeeks.org/problems/check-if-array-contains-duplicates/1
Approach: Hashing via Unordered Set
Time Complexity: O(N)
Space Complexity: O(N) - Worst case storing all unique elements
*/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
  public:
    bool checkDuplicates(vector<int> &arr) {
        unordered_set<int> st;
        
        // Traverse through the array elements
        for (int x : arr) {
            // If element is already present in the set, a duplicate is found
            if (st.find(x) != st.end()) {
                return true;
            }
            // Otherwise, insert the element into the set
            st.insert(x);
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<int> arr1 = {1, 2, 3, 4, 2};
    vector<int> arr2 = {1, 2, 3, 4};

    cout << "Does arr1 have duplicates? " << (s.checkDuplicates(arr1) ? "True" : "False") << endl; // Output: True
    cout << "Does arr2 have duplicates? " << (s.checkDuplicates(arr2) ? "True" : "False") << endl; // Output: False

    return 0;
}