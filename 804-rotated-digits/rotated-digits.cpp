class Solution {
public:
    int rotatedDigits(int n) {
        int rotation[] = {0, 1, 5, -1, -1, 2, 9, -1, 8, 6};
        //                0  1  2   3   4   5  6   7  8  9
        int count = 0;
        
        for (int i = 1; i <= n; i++) {
            string original = to_string(i);
            string rotated = "";
            bool valid = true;
            
            for (char c : original) {
                int digit = c - '0';
                if (rotation[digit] == -1) {
                    valid = false;
                    break;
                }
                rotated += char(rotation[digit] + '0');
            }
            
            if (valid && original != rotated) {
                count++;
            }
        }
        
        return count;
    }
};