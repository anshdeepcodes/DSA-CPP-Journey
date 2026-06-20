/* Problem: Top K Frequent Elements
Platform: GeeksforGeeks (GFG - Medium) / LeetCode 347
Approach: Frequency Map + Min Heap
Time Complexity: O(N * log K) -  N heap insertions, heap size <= K
Space Complexity: O(N + K) - Frequency map + heap
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
  public:
    vector<int> topKFreq(vector<int> &nums, int k) {
        unordered_map<int, int> mp;
        
        // Count frequencies
        for (int val : nums) {
            mp[val]++;
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        
        // Maintain a heap of size K containing the most frequent elements
        for (auto it : mp) {
            min_heap.push({it.second, it.first});
            
            // Remove the least frequent element when heap exceeds size K
            if (min_heap.size() > k) {
                min_heap.pop();
            }
        }
        
        vector<int> result(k);
        for (int i = k - 1; i >= 0; i--) {
            result[i] = min_heap.top().second;
            min_heap.pop();
        }
        
        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    
    vector<int> ans = s.topKFreq(nums, k);
    cout << "Top " << k << " frequent elements: ";
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl; // Output: 1 2
    return 0;
}