/* Problem: Modify and Rearrange Array
Link: https://www.geeksforgeeks.org/problems/ease-the-array0633/1
Approach: Two-Pass (Modify adjacent duplicates + Shift non-zeros to front)
Time Complexity: O(N) - Linear passes
Space Complexity: O(N) - For storing elements in the ans vector
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> modifyAndRearrangeArray(vector<int> &arr) {
        int n = arr.size();

        // Pass 1: Modify adjacent valid duplicates
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] != 0 && arr[i] == arr[i + 1]) {
                arr[i] = 2 * arr[i];
                arr[i + 1] = 0;
            }
        }

        vector<int> ans;

        // Pass 2: Collect all non-zero elements
        for (int i = 0; i < n; i++) {
            if (arr[i] != 0) {
                ans.push_back(arr[i]);
            }
        }

        // Fill the remaining spaces with zeros
        while (ans.size() < n) {
            ans.push_back(0);
        }

        return ans;
    }
};

int main() {
    Solution ob;
    vector<int> arr = {2, 2, 0, 4, 0, 8};
    
    vector<int> res = ob.modifyAndRearrangeArray(arr);
    
    cout << "Modified and Rearranged Array: ";
    for (int x : res) cout << x << " ";
    cout << endl;

    return 0;
}