/* Problem: Next Smaller Element
Platform: GeeksforGeeks (GFG)
Approach: Monotonic Increasing Stack (Right to Left)
Time Complexity: O(N) - Each element is pushed and popped at most once
Space Complexity: O(N) - Stack + Result array
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        int n = arr.size();

        vector<int> ans(n, -1);
        stack<int> st;

        // Traverse from right to left
        for (int i = n - 1; i >= 0; i--) {

            // Remove elements that cannot be the next smaller element
            while (!st.empty() && st.top() >= arr[i]) {
                st.pop();
            }

            // Top of the stack is the next smaller element
            if (!st.empty()) {
                ans[i] = st.top();
            }

            // Push the current element for future comparisons
            st.push(arr[i]);
        }

        return ans;
    }
};

int main() {
    Solution s;

    vector<int> arr = {4, 8, 5, 2, 25};

    vector<int> ans = s.nextSmallerEle(arr);

    cout << "Next Smaller Elements: ";
    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}