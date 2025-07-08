class Solution {
public:
//    int solve(string &text1,string &text2,int i,int j,vector<vector<int>>&dp){
//        if(text1.size()==i){
//         return 0;
//        }
//         if(text2.size()==j){
//         return 0;
//        }
//        if(dp[i][j]!=-1){
//         return dp[i][j];
//        }
//        int ans=0;
//        if(text1[i]==text2[j]){
//         ans=1+solve(text1,text2,i+1,j+1,dp);
//        }
//        else{
//         ans=max(solve(text1,text2,i,j+1,dp),solve(text1,text2,i+1,j,dp));
//        }
//        return dp[i][j]= ans;
//     }
//     int solveTab(string text1,string text2,int i,int j){
//         int ans=0;
//         vector<vector<int>>dp(text1.length()+1,vector<int>(text2.length()+1,0));
//            for(int i=text1.length()-1;i>=0;i--){
//             for(int j=text2.length()-1;j>=0;j--){
                
//        if(text1[i]==text2[j]){
//        ans=1+dp[i+1][j+1];
//        }
//        else{
//         ans=max(dp[i][j+1],dp[i+1][j]);
//        }
//        dp[i][j]=ans;
//             }
//            } 
        
//         return dp[0][0];
//     }
//      int solveTabSO(string text1,string text2,int i,int j){
      
//         // vector<vector<int>>dp(text1.length()+1,vector<int>(text2.length()+1,0));
//         vector<int>curr(text2.length()+1,0);
//         vector<int>prev(text2.length()+1,0);
//         for(int i=text1.length()-1;i>=0;i--){
//             for(int j=text2.length()-1;j>=0;j--){
//              int ans=0;     
//        if(text1[i]==text2[j]){
//        ans=1+prev[j+1];
//        }
//        else{
//         ans=max(prev[j],curr[j+1]);
//        }
//         curr[j]=ans;
//             }
//             prev=curr;
//            } 
        
//         return prev[0];
//     }/
int solve(string &text1, string &text2,int i,int j,vector<vector<int>>&dp){
    if(i>=text1.size()){
        return 0;
    }
     if(j>=text2.size()){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int ans=0;
    if(text1[i]==text2[j]){
        ans= 1+solve(text1,text2,i+1,j+1,dp);
    }
    else{
        ans= max(solve(text1,text2,i,j+1,dp),solve(text1,text2,i+1,j,dp));
    }
    return dp[i][j]= ans;
}
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.length(),vector<int>(text2.length(),-1));
    //   return solve(text1,text2,0,0,dp);  
    int i=0;
    int j=0;
    return solve(text1,text2,i,j,dp);
    }
};