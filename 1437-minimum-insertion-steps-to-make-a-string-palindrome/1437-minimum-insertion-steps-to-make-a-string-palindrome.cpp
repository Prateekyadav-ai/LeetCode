class Solution {
public:
int solve(string &s,int i,int j, vector<vector<int>>&dp){
    if(i>=j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(s[i]==s[j]){
        dp[i][j]= solve(s,i+1,j-1,dp);
    }
    else{
        dp[i][j]= 1+ min(solve(s,i,j-1,dp),solve(s,i+1,j,dp));}
        return dp[i][j];
    
}
    int minInsertions(string s) {
        int n=s.length()-1;
        vector<vector<int>> dp(n+100, vector<int>(n+100, -1));
        return solve(s,0,n,dp);
    }
};