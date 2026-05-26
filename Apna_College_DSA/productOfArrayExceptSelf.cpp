/* Problem: Product of Array Except Self (LeetCode 238)
Course: Apna College DSA (Shradha Didi)
Approach: Two-Pass Prefix and Suffix Product (Optimal)
Time Complexity: O(N) - Two linear passes
Space Complexity: O(1) - Modifying the result vector in-place without extra prefix/suffix arrays
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n, 1);
        
        // Pass 1: Calculate prefix products and store in res
        int leftProduct = 1;
        for (int i = 0; i < n; i++) {
            res[i] = leftProduct;
            leftProduct *= arr[i];
        }
        
        // Pass 2: Calculate suffix products and multiply with existing prefix products
        int rightProduct = 1;
        for (int i = n - 1; i >= 0; i--) {
            res[i] *= rightProduct;
            rightProduct *= arr[i];
        }
        
        return res;
    }
};

int main() {
    Solution ob;
    vector<int> arr = {10, 3, 5, 6, 2};
    
    vector<int> res = ob.productExceptSelf(arr);
    
    cout << "Product Array Except Self: ";
    for (int x : res) cout << x << " ";
    cout << endl;

    return 0;
}