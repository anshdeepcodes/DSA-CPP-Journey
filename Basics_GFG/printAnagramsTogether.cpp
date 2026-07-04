/* Problem: Print Anagrams Together
Platform: GeeksforGeeks (GFG - Medium) / LeetCode 49
Approach: Hash Map + Sorted String Key
Time Complexity: O(N * K log K) - Sort each string before hashing
Space Complexity: O(N * K) - Hash map keys and grouped strings
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<string>> anagrams(vector<string> &arr)
    {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> ans;
 
        for (string word : arr)
        {
            string key = word;

            // Create a sorted key for grouping anagrams
            sort(key.begin(), key.end());

            // Group words having the same sorted key
            mp[key].push_back(word);
        }

        for (auto &it : mp)
        {
            ans.push_back(it.second);
        }

        return ans;
    }
};

int main()
{
    Solution s;
    vector<string> vec = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result = s.anagrams(vec);

    for (auto &row : result)
    {
        for (auto &str : row)
        {
            cout << str << " ";
        }
        cout << endl;
    }

    return 0;
}