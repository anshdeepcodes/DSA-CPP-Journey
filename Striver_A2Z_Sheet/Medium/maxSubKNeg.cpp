/* Problem: Longest Subarray with Sum K
Link: https://takeuforward.org/plus/dsa/problems/longest-subarray-with-sum-k
Approach: Prefix Sum + Hash Map
TC: O(N) - Single pass
SC: O(N) - Prefix sum to earliest index map
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int longestSubarray(vector<int> &nums, int k)
    {
        long long curr_sum = 0; // Prevent integer overflow
        int maxlen = 0;
        unordered_map<long long, int> mp;

        for (int i = 0; i < nums.size(); i++)
        {
            curr_sum += nums[i];

            // Subarray starting from index 0 directly sums to k
            if (curr_sum == k)
            {
                maxlen = i + 1;
            }

            // Check if a previous prefix sum equals (curr_sum - k)
            if (mp.count(curr_sum - k))
            {
                int len = i - mp[curr_sum - k];
                maxlen = max(maxlen, len);
            }

            // Store only the first occurrence to maximize the subarray length
            if (mp.find(curr_sum) == mp.end())
            {
                mp[curr_sum] = i;
            }
        }

        return maxlen;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {-5, 8, -14, 2, 4, 12};
    int k = -5;
    cout << "Longest Subarray Length: " << sol.longestSubarray(nums, k) << endl; // Output: 5
    return 0;
}