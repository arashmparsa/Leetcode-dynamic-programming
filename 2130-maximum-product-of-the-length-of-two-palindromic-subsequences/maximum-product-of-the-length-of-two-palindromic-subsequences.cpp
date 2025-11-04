class Solution {
public:
    int maxProduct(string s) {
        int n = s.length();
        vector<pair<int, int>> arr;  // (mask, length)
        
        // Generate all palindromic subsequences
        for (int mask = 1; mask < (1 << n); mask++) {
            string subseq = "";
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    subseq += s[i];
                }
            }
            
            // Check if palindrome
            string reversed = subseq;
            reverse(reversed.begin(), reversed.end());
            if (subseq == reversed) {
                arr.push_back({mask, (int)subseq.length()});
            }
        }
        
        // Find max product of disjoint pairs
        int result = 1;
        for (int i = 0; i < arr.size(); i++) {
            for (int j = 0; j < arr.size(); j++) {
                int mask1 = arr[i].first;
                int len1 = arr[i].second;
                int mask2 = arr[j].first;
                int len2 = arr[j].second;
                
                // Check if disjoint
                if ((mask1 & mask2) == 0) {
                    result = max(result, len1 * len2);
                }
            }
        }
        
        return result;
    }
};