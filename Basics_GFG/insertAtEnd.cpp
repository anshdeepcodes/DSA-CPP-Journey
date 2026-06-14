/* Problem: Array Insert At End
Link: https://www.geeksforgeeks.org/problems/array-insert-at-end/1
Time Complexity: O(1)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    // Function to insert element at the end of the vector
    void insertAtEnd(vector<int> &arr, int val) {
        arr.push_back(val); // Directly appends the element at the tail of the vector
    }
};

int main() {
    Solution s;
    vector<int> arr = {1, 2, 3, 4};
    int val = 5;

    s.insertAtEnd(arr, val);

    cout << "Array after insertion: ";
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl; // Output: 1 2 3 4 5

    return 0;
}