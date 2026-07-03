/* Problem: Subarray Sum Equals K
   Platform: GeeksforGeeks (GFG - Medium) / LeetCode 560
   Approach: Prefix Sum + Hash Map (Optimal)
   Time Complexity: O(N) - Single pass with hash map lookups
   Space Complexity: O(N) - Prefix sum frequency map
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int cntSubarrays(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        int curr_sum = 0;
        int count = 0;

        // Base case for subarrays starting at index 0
        mp[0] = 1;

        for (int x : nums)
        {
            curr_sum += x; // Update the current prefix sum

            // Find a previous prefix sum that makes the current subarray sum equal to k
            if (mp.count(curr_sum - k))
            {
                count += mp[curr_sum - k];
            }

            // Store the frequency of the current prefix sum
            mp[curr_sum]++;
        }

        return count;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 1, 1};
    int k = 2;

    int result = s.cntSubarrays(nums, k);
    cout << "Total subarrays with sum " << k << " is: " << result << endl; // Output: 2
    return 0;
}