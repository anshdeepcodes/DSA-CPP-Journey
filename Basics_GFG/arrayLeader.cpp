/* 
Problem: Leaders in an Array
Link: https://www.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1
Approach: Right-to-Left Scan (Optimal)
Time Complexity: O(N)
Space Complexity: O(N) to store the leaders
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
        int n = arr.size();
        vector<int> result;
        
        // Rightmost element is always a leader
        int max_from_right = arr[n - 1];
        result.push_back(max_from_right);
    
        // Scan array from right to left
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] >= max_from_right) {
                max_from_right = arr[i];
                result.push_back(max_from_right);
            }
        }
    
        // Reverse to maintain original order
        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    Solution ob;
    vector<int> arr = {16, 17, 4, 3, 5, 2};
    
    vector<int> res = ob.leaders(arr);
    
    cout << "Leaders: ";
    for (int x : res) cout << x << " ";
    cout << endl;

    return 0;
}