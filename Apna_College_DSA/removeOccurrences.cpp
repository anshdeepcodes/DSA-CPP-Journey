/* Problem: Remove All Occurrences of a Substring
Platform: LeetCode 1910
Approach: Stack Simulation using std::string
TC: O(N * M) - Compare suffix after each insertion
SC: O(N) - Result string
*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string removeOccurrences(string s, string part) {
        int partSize = part.size();
        string res = "";

        for (char ch : s) {
            res.push_back(ch); // Push the current character onto the string stack

            // Check the latest suffix once enough characters are available
            if (res.size() >= partSize) {
                // Remove the suffix if it matches the target substring
                if (res.substr(res.size() - partSize) == part) {
                    res.erase(res.size() - partSize);
                }
            }
        }
        
        return res;
    }
};

int main() {
    Solution solver;
    string s = "daabcbaabcbc";
    string part = "abc";
    
    string result = solver.removeOccurrences(s, part);
    cout << "Final string after removals: " << result << endl; // Output: "dab"
    
    return 0;
}