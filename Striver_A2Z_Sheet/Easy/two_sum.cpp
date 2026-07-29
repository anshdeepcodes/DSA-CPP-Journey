/* Problem: Two Sum
Link: https://takeuforward.org/plus/dsa/problems/two-sum
Platform: TUF+ / LeetCode 1
Approach: Hash Map (One Pass)
TC: O(N)
SC: O(N) - Hash map
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int , int> mp;

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            // Check if the complement has already been seen
            if (mp.find(complement) != mp.end()) {
                return {mp[complement], i};
            }

            // Store the current value and its index
            mp[nums[i]] = i;
        }
        return {};
    }
};

int main(){
    Solution sol;
    vector<int> vec = {1, 3, 5, -7, 6, -3};
    int target = 0;
    vector<int> result = sol.twoSum(vec, target);

    cout << "The indices of target sum " << result[0] << ", " << result[1] << endl; // Output: 1, 5

    return 0;
}
