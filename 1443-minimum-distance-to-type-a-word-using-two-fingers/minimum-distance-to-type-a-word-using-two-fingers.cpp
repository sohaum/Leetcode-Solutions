class Solution {
    int getDist(int a, int b) {
        if (a == 26) return 0;
        int r1 = a / 6, c1 = a % 6;
        int r2 = b / 6, c2 = b % 6;
        return abs(r1 - r2) + abs(c1 - c2);
    }

public:
    int minimumDistance(string word) {
        int n = word.length();
        vector<int> dp(27, 4000); 
        dp[26] = 0;
        for (int i = 0; i < n - 1; i++) {
            int curr = word[i] - 'A';
            int next = word[i+1] - 'A';
            vector<int> next_dp(27, 4000);
            for (int other = 0; other < 27; other++) {
                if (dp[other] == 4000) continue;
                next_dp[other] = min(next_dp[other], dp[other] + getDist(curr, next));
                next_dp[curr] = min(next_dp[curr], dp[other] + getDist(other, next));
            }
            dp = next_dp;
        }
        int minTotal = 4000;
        for (int d : dp) minTotal = min(minTotal, d);
        return minTotal;
    }
};