/* Problem: Find Greatest Common Divisor of Array
Platform: LeetCode 1979 / Apna College Pattern
Approach: Euclidean Algorithm
TC: O(N + log(min(A, B))) // Find min/max, then compute GCD
SC: O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    // Compute GCD using the Euclidean Algorithm
    int gcd(int a, int b) {
        while (a > 0 && b > 0) {
            if (a > b) a %= b;
            else b %= a;
        }
        return (a == 0) ? b : a;
    }

    int findGCD(vector<int>& nums) {
        int maxNum = INT_MIN;
        int minNum = INT_MAX;
        
        // Find min and max elements in a single pass
        for (int x : nums) {
            maxNum = max(maxNum, x);
            minNum = min(minNum, x);
        }

        // Compute the GCD of the smallest and largest elements
        return gcd(maxNum, minNum);
    }
};

int main() {
    Solution solver;
    vector<int> nums = {2, 5, 6, 9, 10};
    
    int result = solver.findGCD(nums);
    cout << "GCD of smallest and largest element: " << result << endl; // Output: 2 (min: 2, max: 10)
    
    return 0;
}