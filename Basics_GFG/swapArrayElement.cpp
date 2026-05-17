/* Problem: Swap Elements (With an offset of 2)
Link: https://www.geeksforgeeks.org/problems/need-some-change/1
Approach: Iterative Swap with i and i+2
Time Complexity: O(N)
Space Complexity: O(1) as we are modifying the array in-place
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    void swapElements(vector<int> &arr) {
        int n = arr.size();
        
        // Loop runs till n-2 to avoid out of bound exception for i+2
        for (int i = 0; i < n - 2; i++) {
            // Using built-in swap function of C++
            swap(arr[i], arr[i + 2]);
        }
    }
};

int main() {
    Solution ob;
    vector<int> arr = {1, 2, 3, 4, 5};
    
    ob.swapElements(arr);
    
    cout << "Array after swapping: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}