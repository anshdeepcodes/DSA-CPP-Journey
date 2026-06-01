/* Problem: Peak Index in a Mountain Array (LeetCode 852)
Course: Apna College DSA (Shradha Didi)
Approach: Binary Search on Mountain Slope (Optimal)
Time Complexity: O(log N)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        // st=1 and end=size-2 to safely check mid-1 and mid+1 without out-of-bound errors
        int st = 1, end = arr.size() - 2; 
        
        while (st <= end) {
            int mid = st + (end - st) / 2;

            // If mid is greater than both its neighbors, it is the peak element
            if ((arr[mid] > arr[mid - 1]) && (arr[mid] > arr[mid + 1])) {
                return mid;
            }
            // If mid is greater than mid-1, we are on the increasing slope -> Peak is in the right half
            else if (arr[mid - 1] < arr[mid]) {
                st = mid + 1;
            }
            // Otherwise, we are on the decreasing slope -> Peak is in the left half
            else {
                end = mid - 1;
            }
        }
        
        // Return -1 if no peak element is found (fallback)
        return -1;
    }
};

int main() {
    Solution s;
    // Classic mountain array example [Increasing then Decreasing]
    vector<int> arr = {0, 2, 4, 10, 5, 2, 0}; 
    
    int peakIndex = s.peakIndexInMountainArray(arr);
    cout << "The peak element is at index: " << peakIndex << " (Element: " << arr[peakIndex] << ")" << endl; // Output: 3
    
    return 0;
}