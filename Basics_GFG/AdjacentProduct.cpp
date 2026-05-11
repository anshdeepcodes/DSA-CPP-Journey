/* Problem: Replace every element with the product of previous and next
Link: https://www.geeksforgeeks.org/problems/replace-with-adjacent-multiplication/1
Approach: Iterative with Boundary Checks (Using Ternary Operators)
Time Complexity: O(N)
Space Complexity: O(N) for result vector
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> updateProductArray(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return {};
        if (n == 1) return arr; // Corner case for single element

        vector<int> result(n);

        for (int i = 0; i < n; i++) {
            // Logic: result[i] = arr[i-1] * arr[i+1]
            // Boundary checks as per GFG:
            int prev = (i > 0) ? arr[i - 1] : 1;
            int curr = arr[i];
            int next = (i < n - 1) ? arr[i + 1] : 1;

            result[i] = prev * curr * next;
        }

        return result;
    }
};

int main() {
    Solution ob;
    vector<int> arr = {2, 3, 4, 5, 6};
    
    vector<int> res = ob.updateProductArray(arr);
    
    cout << "Updated Array: ";
    for (int x : res) cout << x << " ";
    cout << endl;

    return 0;
}