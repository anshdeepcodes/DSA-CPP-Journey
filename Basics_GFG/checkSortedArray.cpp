/* Problem: Check if Array is Sorted
Link: https://www.geeksforgeeks.org/problems/check-if-an-array-is-sorted0701/1
Time Complexity: O(N)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    bool isSorted(vector<int>& arr) {
        // An array with a single element is always sorted
        if (arr.size() == 1) return true;
        
        // Compare current element with the next element
        for (int i = 0; i < arr.size() - 1; i++) {
            // If any element is greater than its successor, array is unsorted
            if (arr[i] > arr[i + 1]) {
                return false;
            }
        }
        
        return true;
    }
};

int main() {
    Solution s;
    vector<int> arr1 = {10, 20, 30, 40, 50};
    vector<int> arr2 = {90, 80, 100, 70, 40};

    cout << "Is arr1 sorted? " << (s.isSorted(arr1) ? "True" : "False") << endl; // Output: True
    cout << "Is arr2 sorted? " << (s.isSorted(arr2) ? "True" : "False") << endl; // Output: False

    return 0;
}