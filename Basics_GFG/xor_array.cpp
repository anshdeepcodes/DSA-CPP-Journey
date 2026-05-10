/* Problem: Replace elements with XOR of neighbors
Link: https://www.geeksforgeeks.org/problems/play-with-or5515/1
Approach: Iterative with prev variable (Space Optimized)
Time Complexity: O(N)
Space Complexity: O(1) 
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    void updateArray(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return;
    
        // Store the first element before modifying it
        int prev = arr[0];
        
        // For the first element, neighbor is only arr[1]
        // (Assuming the logic is based on your code: arr[0] ^ arr[1])
        arr[0] = arr[0] ^ arr[1];
    
        for (int i = 1; i < n - 1; i++) {
            int current = arr[i]; // Store current value to be 'prev' for next iteration
            arr[i] = prev ^ arr[i + 1];
            prev = current; 
        }

        // For the last element, neighbor is the original arr[n-2] (now in 'prev')
        arr[n - 1] = prev ^ arr[n - 1];
    }
};

int main() {
    Solution ob;
    vector<int> arr = {2, 3, 4, 5, 6};
    
    ob.updateArray(arr);
    
    cout << "Updated Array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}