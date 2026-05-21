/* Problem: Return Array and String Form of Three Numbers
Link: https://www.geeksforgeeks.org/problems/choice/1
Approach: Standard Vector Initialization and to_string() Concatenation
Time Complexity: O(1)
Space Complexity: O(1) / O(N) for storing the result string/vector
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
  public:
    vector<int> arrayForm(int a, int b, int c) {
        vector<int> res = {a, b, c};
        return res;
    }

    string stringForm(int a, int b, int c) {
        // to_string converts integers to characters before concatenation
        string res = to_string(a) + to_string(b) + to_string(c);
        return res;
    }
};

int main() {
    Solution ob;
    int a = 1, b = 2, c = 3;
    
    vector<int> arr = ob.arrayForm(a, b, c);
    string str = ob.stringForm(a, b, c);
    
    cout << "Array Form: ";
    for (int x : arr) cout << x << " ";
    cout << endl;
    
    cout << "String Form: " << str << endl;

    return 0;
}