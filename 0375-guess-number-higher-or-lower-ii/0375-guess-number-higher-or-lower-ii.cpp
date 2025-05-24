class Solution {
public:
int solve(int s,int e){
    //base case
    if(s>=e){
        return 0;
    }
    int ans=INT_MAX;
    for(int i=s;i<=e;i++){
     ans=min(ans,i+max(solve(s,i-1),solve(i+1,e)));
    }
 return ans;
}
int solveMemo(int s,int e,vector<vector<int>>&dp){
    //base case
    if(s>=e){
        return 0;
    }
    if(dp[s][e]!=-1){
        return dp[s][e];
    }
    int ans=INT_MAX;
    for(int i=s;i<e;i++){
     ans=min(ans,i+max(solveMemo(s,i-1,dp),solveMemo(i+1,e,dp)));
    }
    dp[s][e]=ans;
 return dp[s][e];
}
    int getMoneyAmount(int n) {
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
       return solveMemo(1,n,dp); 
    }
};