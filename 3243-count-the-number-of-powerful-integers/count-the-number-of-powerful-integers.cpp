class Solution {
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        // Convert to string representation for digit DP
        string low = to_string(start - 1);
        string high = to_string(finish);
        
        // Pad low with leading zeros to match high's length
        low = string(high.length() - low.length(), '0') + low;
        
        // Memoization for digit DP
        vector<vector<long long>> memo_low(high.length(), vector<long long>(2, -1));
        vector<vector<long long>> memo_high(high.length(), vector<long long>(2, -1));
        
        // DP function: count numbers <= num_str that end with suffix s and have all digits <= limit
        function<long long(int, bool, const string&, vector<vector<long long>>&)> dp = 
            [&](int pos, bool tight, const string& num_str, vector<vector<long long>>& memo) -> long long {
            int n = num_str.length();
            int m = s.length();
            
            if (pos == n) {
                // Check if the suffix matches
                return 1;
            }
            
            // In suffix region, digits are fixed
            if (pos >= n - m) {
                int suffix_pos = m - (n - pos);
                int required_digit = s[suffix_pos] - '0';
                
                if (tight && required_digit > num_str[pos] - '0') {
                    return 0;
                }
                
                bool new_tight = tight && (required_digit == num_str[pos] - '0');
                return dp(pos + 1, new_tight, num_str, memo);
            }
            
            if (memo[pos][tight] != -1) {
                return memo[pos][tight];
            }
            
            long long count = 0;
            int max_digit = tight ? (num_str[pos] - '0') : limit;
            
            for (int digit = 0; digit <= max_digit; digit++) {
                if (digit > limit) continue;
                
                bool new_tight = tight && (digit == max_digit);
                count += dp(pos + 1, new_tight, num_str, memo);
            }
            
            return memo[pos][tight] = count;
        };
        
        long long count_high = dp(0, true, high, memo_high);
        long long count_low = dp(0, true, low, memo_low);
        
        return count_high - count_low;
    }
};