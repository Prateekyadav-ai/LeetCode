class Solution {
public:
    int fun(int ind, bool buy, vector<int>& prices, vector<vector<vector<int>>>& dp, int cap) {
        if (cap == 0 || ind >= prices.size())
            return 0;
        if (dp[ind][buy][cap] != -1)
            return dp[ind][buy][cap];
        int ans = 0;
        if (buy)
            ans = max(-prices[ind] + fun(ind + 1, 0, prices, dp, cap), fun(ind + 1, 1, prices, dp, cap));
        else
            ans = max(prices[ind] + fun(ind + 1, 1, prices, dp, cap - 1),fun(ind + 1, 0, prices, dp, cap));
        return dp[ind][buy][cap] = ans;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size() + 1,vector<vector<int>>(2,vector<int>(3,-1)));
        return fun(0, 1, prices, dp, 2); 
    }
};