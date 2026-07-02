/* Problem: Find Median from Data Stream (Running Median)
Platform: GeeksforGeeks (GFG - Hard) / LeetCode 295
Approach: Two Heaps (Max Heap + Min Heap)
Time Complexity: O(N log N) // O(log N) insertion per element
Space Complexity: O(N) // Two Heaps
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        vector<double> res;
        priority_queue<int> max_heap; // Smaller half
        priority_queue<int, vector<int>, greater<int>> min_heap; // Larger half
        
        for (int num : arr) {
            // Insert into the appropriate heap
            if (max_heap.empty() || num <= max_heap.top()) {
                max_heap.push(num);
            } else {
                min_heap.push(num);
            }
    
            // Rebalance heaps to maintain size constraint (max_heap can have at most 1 extra element)
            if (max_heap.size() > min_heap.size() + 1) {
                min_heap.push(max_heap.top());
                max_heap.pop();
            } else if (min_heap.size() > max_heap.size()) {
                max_heap.push(min_heap.top());
                max_heap.pop();
            }  
        
            // Calculate the running median
            if (max_heap.size() == min_heap.size()) {
                res.push_back((max_heap.top() + min_heap.top()) / 2.0);
            } else {
                res.push_back(max_heap.top());
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> arr = {5, 15, 1, 2};
    
    vector<double> medians = s.getMedian(arr);
    
    cout << "Running Medians: ";
    for (double m : medians) {
        cout << m << " ";
    }
    cout << endl; // Output: 5 10 5 4
    return 0;
}