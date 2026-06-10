/* Problem: Merge Sorted Array
Course: Apna College DSA (Shradha Didi)
Approach: Three-Pointer Backward Merging (Optimal & In-place)
Time Complexity: O(m + n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int> &arr1, int m, vector<int> &arr2, int n) {
        int k = m + n - 1; // Pointer for the last position in arr1
        int i = m - 1;     // Pointer for the last valid element in arr1
        int j = n - 1;     // Pointer for the last element in arr2

        // Merge arrays from back to front by picking the larger element
        while (i >= 0 && j >= 0) {
            if (arr1[i] >= arr2[j]) {
                arr1[k--] = arr1[i--];
            } else {
                arr1[k--] = arr2[j--];
            }
        }

        // If elements are left in arr2, copy them over
        while (j >= 0) {
            arr1[k--] = arr2[j--];
        }
    }
};

int main() {
    Solution s;
    // arr1 has total size of 6, but only 3 elements are initially valid
    vector<int> arr1 = {1, 2, 3, 0, 0, 0}; 
    vector<int> arr2 = {2, 5, 6};
    int m = 3, n = 3;

    s.merge(arr1, m, arr2, n);

    cout << "Merged Array: ";
    for (int x : arr1) {
        cout << x << " ";
    }
    cout << endl; // Output: 1 2 2 3 5 6

    return 0;
}