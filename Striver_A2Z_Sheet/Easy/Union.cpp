/*
Problem: Union of Two Sorted Arrays
Link: https://takeuforward.org/plus/dsa/problems/union-of-two-sorted-arrays
Platform: TUF+ [Striver Sheet]
Approach: Two-Pointer (Optimal for Sorted Arrays)
Time Complexity: O(n + m) - Single pass through both arrays
Space Complexity: O(n + m) - To store the result
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        int i = 0, j = 0;
        vector<int> res;

        // Traverse both arrays using two pointers
        while (i < a.size() && j < b.size()) {
            int val;
            
            // Compare elements and pick the smaller one to maintain order
            if (a[i] < b[j]) {
                val = a[i++];
            } else if (a[i] > b[j]) {
                val = b[j++];
            } else {
                // If elements are equal, pick any one and move both pointers
                val = a[i];
                i++; j++;
            }

            // Duplicate Check: Add to result only if it's the first element 
            // or different from the last added element
            if (res.empty() || res.back() != val) {
                res.push_back(val);
            }
        }

        // Add remaining elements from array 'a', checking for duplicates
        while (i < a.size()) {
            if (res.empty() || res.back() != a[i]) {
                res.push_back(a[i]);
            }
            i++;
        }

        // Add remaining elements from array 'b', checking for duplicates
        while (j < b.size()) {
            if (res.empty() || res.back() != b[j]) {
                res.push_back(b[j]);
            }
            j++;
        }

        return res;
    }
};

int main() {
    Solution sol;
    
    // Example test case with duplicates
    vector<int> a = {1, 2, 3, 4, 5, 5, 5};
    vector<int> b = {2, 3, 4, 4, 5, 6};

    vector<int> result = sol.findUnion(a, b);

    cout << "Union of Arrays: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}