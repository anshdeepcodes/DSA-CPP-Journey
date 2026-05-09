/* 
Problem: First Occurrence in Sorted Array
Link: https://www.geeksforgeeks.org/problems/first-and-last-occurrences-of-x3116/1
Approach: Modified Binary Search
Time Complexity: O(log N)
Space Complexity: O(1) 
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int firstSearch(vector<int> &arr, int k) {
        int low = 0, high = arr.size() - 1;
        int result = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == k) {
                result = mid;     // Potential answer found
                high = mid - 1;   // Keep searching on the left side for "first" occurrence
            } 
            else if (arr[mid] < k) {
                low = mid + 1;
            } 
            else {
                high = mid - 1;
            }
        }
        return result;
    }
};

int main() {
    Solution ob;
    vector<int> arr = {1, 2, 2, 2, 3, 4, 5};
    int k = 2;
    
    int index = ob.firstSearch(arr, k);
    if (index != -1)
        cout << "First occurrence of " << k << " is at index: " << index << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}