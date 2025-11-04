#include <vector>
class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        const int MOD = 1e9 + 7;
        
        // dp[i][j] = number of ways to roll i dice to get sum j
        vector<vector<long long>> dp(n + 1, vector<long long>(target + 1, 0));
        
        // Base case: 0 dice with sum 0
        dp[0][0] = 1;
        
        // Fill the dp table
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= min(target, i * k); j++) {
                // Try each face value 1 to k
                for (int face = 1; face <= k && face <= j; face++) {
                    dp[i][j] = (dp[i][j] + dp[i-1][j-face]) % MOD;
                }
            }
        }
        
        return dp[n][target];
    }
};