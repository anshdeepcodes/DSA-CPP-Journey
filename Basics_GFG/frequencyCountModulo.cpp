/* Problem: Frequencies of Limited Range Array Elements
LInk: https://www.geeksforgeeks.org/problems/frequency-of-array-elements-1587115620/1
Approach: Mathematical Modulo Hashing (Optimal)
Time Complexity: O(N)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> frequencyCount(vector<int>& arr) {
        int n = arr.size();
        int k = n + 1; // Base multiplier

        // Pre-process elements to clear values greater than N
        for (int i = 0; i < n; i++) {
            if (arr[i] > n) {
                arr[i] = 0; // Out of range elements won't contribute to 1...N counts
            }
        }
        
        // Encode frequencies into the array
        for (int i = 0; i < n; i++) {
            int original_val = arr[i] % k;
            
            // Only update if the mapped index is valid
            if (original_val > 0 && original_val <= n) {
                int idx = original_val - 1;
                arr[idx] += k;
            }
        }
        
        // Decode to extract only the frequency count
        for (int i = 0; i < n; i++) {
            arr[i] /= k;
        }

        return arr;
    }
};

int main() {
    Solution s;
    vector<int> arr = {7, 2, 3, 2, 3, 5};
    
    s.frequencyCount(arr);
    
    cout << "Frequencies: ";
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl; // Output: 0 2 2 0 1
    return 0;
}
