/* Problem: Majority Element (Moore’s Voting Algorithm)
Link: https://www.geeksforgeeks.org/problems/majority-element-1587115620/1
Approach: Moore's Voting Algorithm + Verification Pass
Time Complexity: O(N)
Space Complexity: O(1) 
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        int freq = 0; 
        int ans = 0;
        
        // Phase 1: Finding the candidate for Majority Element
        for (int i = 0; i < arr.size(); i++) {
            if (freq == 0) {
                ans = arr[i];
            }
            if (ans == arr[i]) {
                freq++;
            }
            else {
                freq--;
            }
        }
        
        // Phase 2: Verifying if the candidate is actually the majority
        freq = 0;
        for (int val : arr) {
            if (val == ans) {
                freq++;
            }
        }
        
        // Check if frequency is more than n/2
        return (freq > arr.size() / 2) ? ans : -1;
    }
};

int main() {
    Solution ob;
    vector<int> arr = {3, 1, 3, 3, 2};
    
    int result = ob.majorityElement(arr);
    if (result != -1)
        cout << "Majority Element: " << result << endl;
    else
        cout << "No Majority Element found" << endl;

    return 0;
}