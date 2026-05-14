/* 
Problem: Alternates in an Array
Link: https://www.geeksforgeeks.org/problems/print-alternate-elements-of-an-array/1
Approach: Iterative with step of 2
Time Complexity: O(N)
Space Complexity: O(N) for result vector
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> getAlternates(vector<int> &arr) {
        vector<int> result;
        // Jump by 2 to get every alternate element
        for (int i = 0; i < arr.size(); i += 2) {
            result.push_back(arr[i]);
        }
        return result;
    }
};

int main() {
    Solution ob;
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    
    vector<int> res = ob.getAlternates(arr);
    
    cout << "Alternate Elements: ";
    for (int x : res) cout << x << " ";
    cout << endl;

    return 0;
}