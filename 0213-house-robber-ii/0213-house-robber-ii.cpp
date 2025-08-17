class Solution {
public:
    int solve(vector<int>& nums, int start, int end, vector<int>& dp) {
        if (start > end) return 0;

        if (dp[start] != -1) return dp[start];

        int option1 = nums[start] + solve(nums, start + 2, end, dp);
        int option2 = solve(nums, start + 1, end, dp);

        return dp[start] = max(option1, option2);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        vector<int> dp1(n, -1);  // Exclude last house
        vector<int> dp2(n, -1);  // Exclude first house

        int option1 = solve(nums, 0, n - 2, dp1);  // Rob from 0 to n-2
        int option2 = solve(nums, 1, n - 1, dp2);  // Rob from 1 to n-1

        return max(option1, option2);
    }
};
