/* Problem: Best Time to Buy and Sell Stock (LeetCode 121)
Course: Apna College DSA (Shradha Didi)
Approach: Greedy / Single Pass (Optimal)
Time Complexity: O(N) - Linear scan of the prices array
Space Complexity: O(1) - No extra space used
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;

        int maxProfit = 0;
        int bestBuy = prices[0]; // Assume first day is the best day to buy

        for(size_t i = 1; i < prices.size(); i++) {
            // If current price is greater than our best buy, calculate potential profit
            if(prices[i] > bestBuy) {
                maxProfit = max(maxProfit, prices[i] - bestBuy);
            }
            // Update the minimum buying price seen so far
            bestBuy = min(bestBuy, (int)prices[i]);
        }
        
        return maxProfit;
    }
};

int main() {
    Solution s;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    
    cout << "Max Profit: " << s.maxProfit(prices) << endl; // Output: 5 (Buy on day 2 @ 1, Sell on day 5 @ 6)
    return 0;
}