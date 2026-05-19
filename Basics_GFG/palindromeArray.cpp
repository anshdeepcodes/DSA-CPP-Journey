/* Problem: Array Palindrome
Link: http://geeksforgeeks.org/problems/perfect-arrays4645/1
Approach: Two-Pointer Technique (Optimal)
Time Complexity: O(N)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    bool isPalindrome(vector<int> &arr) {
        int left = 0;
        int right = arr.size() - 1;
        
        // Move pointers towards the center
        while (left < right) {
            if (arr[left] != arr[right]) {
                return false; // Elements don't match, not a palindrome
            }
            left++;
            right--;
        }
        
        return true; // All elements matched
    }
};

int main() {
    Solution ob;
    vector<int> arr = {1, 2, 3, 2, 1};
    
    if (ob.isPalindrome(arr)) {
        cout << "True: Array is a palindrome." << endl;
    } else {
        cout << "False: Array is not a palindrome." << endl;
    }

    return 0;
}