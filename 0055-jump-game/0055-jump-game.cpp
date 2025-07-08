class Solution {
public:
bool solve(vector<int>& nums,int i,vector<int>&dp){
   /// if(nums[i]==0)return false;
   int n=nums.size();
    if(i>=n) return false;
    if(i==n-1)return true;
    if(dp[i]!=-1){
        return dp[i];
    }
    bool reans=false;
    for(int jump=1;jump<=nums[i];jump++){
       if (solve(nums, i + jump, dp)) {
                return dp[i] = true;     
            }
        }
        return dp[i] = false;           
    
}
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+100,-1);
        return solve(nums,0,dp);
    }
};