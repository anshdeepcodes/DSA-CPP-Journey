/* 
Problem: Find Minimum and Maximum element in an array
Link: https://www.geeksforgeeks.org/problems/find-minimum-and-maximum-element-in-an-array4428/1?
Approach: Single Traversal
Time Complexity: O(N) 
Space Complexity: O(1) 
*/

#include <iostream>
#include <vector>
#include <climits> // For INT_MIN and INT_MAX

using namespace std;

class Solution {
  public:
    // Function to find the minimum and maximum elements in an array
    vector<int> getMinMax(vector<int> &arr) {
        // Initialize min with a very large value and max with a very small value
        int minElement = INT_MAX;
        int maxElement = INT_MIN;

        // Traverse the entire array
        for (int i = 0; i < arr.size(); i++) {
            // Update maxElement if current element is greater
            if (arr[i] > maxElement) {
                maxElement = arr[i];
            }
            // Update minElement if current element is smaller
            if (arr[i] < minElement) {
                minElement = arr[i];
            }
        }
        
        // Return results as a vector: {min, max}
        return {minElement, maxElement};
    }
};

// Driver Code (main function) to test the logic
int main() {
    Solution ob;
    
    // Test Case
    vector<int> arr = {3, 2, 1, 56, 10000, 167};
    
    // Call the function
    vector<int> result = ob.getMinMax(arr);
    
    // Output the results
    cout << "Minimum Element: " << result[0] << endl;
    cout << "Maximum Element: " << result[1] << endl;

    return 0;
}