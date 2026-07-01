/* Problem: Intersection of Two Arrays (Unique Elements Variant)
Platform: GeeksforGeeks (GFG - Easy) / LeetCode 349
Approach: Hash Set with Element Removal (Optimal)
Time Complexity: O(N + M) // Build set + traverse second array
Space Complexity: O(N)    // Hash set
*/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
  public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        // Store all unique elements of nums1 in a set
        unordered_set<int> myUnorderedSet(nums1.begin(), nums1.end());

        // Iterate through nums2 and find matches
        for (int element : nums2) {
            if (myUnorderedSet.find(element) != myUnorderedSet.end()) {
                res.push_back(element);
                // Remove the element so it appears only once in the result
                myUnorderedSet.erase(element);
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> a = {1, 2, 1, 3, 1};
    vector<int> b = {3, 1, 3, 4, 1};
    
    vector<int> output = s.intersect(a, b);
    
    cout << "Unique Intersection: ";
    for (int x : output) {
        cout << x << " ";
    }
    cout << endl; 
    return 0;
}