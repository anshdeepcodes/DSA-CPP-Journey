/* Problem: Count Primes
Platform: LeetCode 204
Approach: Sieve of Eratosthenes
Time Complexity: O(N log log N)
Space Complexity: O(N)
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrime(n, true);

        int count = 0;

        // Mark multiples of every prime number
        for (int i = 2; i < n; i++) {
            if (isPrime[i]) {
                count++;

                for (int j = i * 2; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        return count;
    }
};

int main() {
    Solution s;

    int n = 10;

    cout << "Number of Primes: " << s.countPrimes(n);

    return 0;
}