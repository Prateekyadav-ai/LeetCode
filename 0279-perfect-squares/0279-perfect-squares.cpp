class Solution {
public:
    int numsquarehelper(int n, vector<int>& dp) {
        if (n == 0) return 0;
        if (n < 0) return INT_MAX;
        
        if (dp[n] != -1) return dp[n];

        int ans = INT_MAX;
        for (int i = 1; i * i <= n; i++) {
            int square = i * i;
            int res = numsquarehelper(n - square, dp);
            if (res != INT_MAX) {
                ans = min(ans, 1 + res);
            }
        }
        dp[n] = ans;
        return dp[n];
    }

    int numSquares(int n) {
        vector<int> dp(n + 1, -1);
        return numsquarehelper(n, dp);
    }
};
