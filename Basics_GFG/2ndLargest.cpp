/* Problem: Second Largest Element
Link: https://www.geeksforgeeks.org/problems/second-largest3735/1
Approach: Single Pass (Optimal)
Time Complexity: O(N)
Space Complexity: O(1) 
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        int n = arr.size();
        if (n < 2) return -1;

        int largest = -1;
        int secondLargest = -1;

        for (int i = 0; i < n; i++) {
            // If current element is greater than largest
            if (arr[i] > largest) {
                secondLargest = largest;
                largest = arr[i];
            }
            // If current element is between largest and secondLargest
            else if (arr[i] < largest && arr[i] > secondLargest) {
                secondLargest = arr[i];
            }
        }

        return secondLargest;
    }
};

int main() {
    Solution ob;
    vector<int> arr = {12, 35, 1, 10, 34, 1};
    
    int result = ob.getSecondLargest(arr);
    cout << "Second Largest Element: " << result << endl;

    return 0;
}