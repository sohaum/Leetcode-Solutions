class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n=lcp.size();
        string s(n,'?');
        char curr = 'a';
        // Step 1: Assign characters
        for (int i=0; i<n; i++) {
            if (s[i] != '?') continue;
            if (curr > 'z') return "";
            s[i] = curr;
            for (int j = i + 1; j < n; j++) {
                if (lcp[i][j] > 0) {
                    s[j] = curr;
                }
            }
            curr++;
        }\
        // Step 2: Validate LCP
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int i= n-1; i>=0; i--) {
            for (int j = n-1; j>=0; j--) {
                if (s[i] == s[j]) {
                    dp[i][j] = 1 + dp[i+1][j+1];
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        // Step 3: Compare with given LCP
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (dp[i][j] != lcp[i][j]) {
                    return "";
                }
            }
        }
        return s;
    }
};