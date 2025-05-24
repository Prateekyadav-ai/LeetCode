class Solution {
public:
    int solve(vector<int>& nums, int i,vector<int>&dp) {
        // Base case: if we reach or pass the last index
        if (i >= nums.size() - 1) return 0;
        if(dp[i]!=-1){
            return dp[i];
        }
        int minJumps = INT_MAX;

        for (int j = 1; j <= nums[i]; ++j) {
            // Include: take a jump of length j
            int include = solve(nums, i + j,dp);
            if (include != INT_MAX) {
                minJumps = min(minJumps, 1 + include); // Include this jump
                
            }

            // Exclude is naturally handled by the loop continuing to try other j
        }

        return dp[i]=minJumps;
    }

    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return solve(nums, 0,dp);
    }
};
