/* Problem: First and Last Occurrences of x
Link: https://www.geeksforgeeks.org/problems/first-and-last-occurrences-of-x3116/1
Approach: Nested Binary Search (Highly Optimal)
Time Complexity: O(log N) - All search spaces are divided by 2
Space Complexity: O(1) - Constant auxiliary space
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> find(vector<int> &arr, int x) {
        int low = 0;
        int high = arr.size() - 1;
        
        // Main Binary Search Loop to find the element
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            // Element found! Now finding exact boundaries
            if (x == arr[mid]) {
                int first = mid;
                int last = mid;
                
                // Sub-Binary Search 1: Search in the left half for the FIRST occurrence
                int l = low, h = mid - 1;
                while (l <= h) {
                    int m = l + (h - l) / 2;
                    if (x == arr[m]) {
                        first = m;     // Potential first occurrence found
                        h = m - 1;     // Keep looking left
                    } else {
                        l = m + 1;
                    }
                }
                
                // Sub-Binary Search 2: Search in the right half for the LAST occurrence
                l = mid + 1, h = high;
                while (l <= h) {
                    int m = l + (h - l) / 2;
                    if (x == arr[m]) {
                        last = m;      // Potential last occurrence found
                        l = m + 1;     // Keep looking right
                    } else {
                        h = m - 1;
                    }
                }
                
                return {first, last};
            }
            // If element is larger, discard the left half
            else if (x > arr[mid]) {
                low = mid + 1;
            }
            // If element is smaller, discard the right half
            else {
                high = mid - 1;
            }
        }
        
        // Element not present in the array
        return {-1, -1};
    }
};

int main() {
    Solution s;
    vector<int> arr = {1, 3, 5, 5, 5, 5, 67, 123, 125};
    int k = 5;
    
    vector<int> result = s.find(arr, k);
    cout << "First Occurrence: " << result[0] << endl; // Output: 2
    cout << "Last Occurrence: " << result[1] << endl;  // Output: 5
    
    return 0;
}