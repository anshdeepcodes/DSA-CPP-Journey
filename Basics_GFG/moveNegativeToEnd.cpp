/* Problem: Move all negative elements to end
Link: https://www.geeksforgeeks.org/problems/move-all-negative-elements-to-end1813/1
Approach: Two-Pass Stable Segregation using Auxiliary Vector
Time Complexity: O(N) - Linear passes
Space Complexity: O(N) - For storing elements in temp vector
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    void segregateElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> temp;
        
        // Pass 1: Push all positive elements and zeros to temp
        for (int i = 0; i < n; i++) {
            if (arr[i] >= 0) {
                 temp.push_back(arr[i]);
            }
        }
        
        // Pass 2: Push all negative elements to temp
        for (int i = 0; i < n; i++) {
            if (arr[i] < 0) {
                temp.push_back(arr[i]);
            }
        }
        
        // Copy back the segregated elements to the original array
        for (int i = 0; i < n; i++) {
            arr[i] = temp[i];
        }
    }
};

int main() {
    Solution ob;
    vector<int> arr = {1, -1, 3, 2, -7, -5, 11, 6};
    
    ob.segregateElements(arr);
    
    cout << "Segregated Array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}