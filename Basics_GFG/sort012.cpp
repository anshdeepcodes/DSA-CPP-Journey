/* 
Problem: Sort 0s, 1s and 2s (Sort Colors)
Link: https://www.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1
Approach: Dutch National Flag Algorithm (Three-way Partitioning)
Time Complexity: O(N)
Space Complexity: O(1) 
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    void sort012(vector<int>& arr) {
        int low = 0;
        int mid = 0;
        int high = arr.size() - 1;
        
        while (mid <= high) {
            if (arr[mid] == 0) {
                // Move 0s to the left
                swap(arr[mid], arr[low]);
                low++;
                mid++;
            }
            else if (arr[mid] == 1) {
                // 1s are already in the middle, just move forward
                mid++;
            }
            else if (arr[mid] == 2) {
                // Move 2s to the right
                swap(arr[mid], arr[high]);
                high--;
                // Note: We don't increment mid here because the swapped 
                // element from 'high' needs to be checked.
            }
        }
    }
};

int main() {
    Solution ob;
    vector<int> arr = {0, 1, 2, 0, 1, 2};
    
    ob.sort012(arr);
    
    cout << "Sorted Array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}