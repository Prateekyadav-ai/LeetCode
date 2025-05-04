class Solution {
public:
int bruteforce(int m,int n){
     vector<vector<int>> arr(m, vector<int>(n, 0));;
       for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0||j==0){
             arr[i][j]=1;
            }
            else{
                arr[i][j]=arr[i-1][j]+arr[i][j-1];
            }
        }
       }
       return arr[m-1][n-1];
}
    int uniquePaths(int m, int n) {
        int dp[m+1][n+1] ;
        for(int i=0;i<m;i++){
            dp[i][0] = 1;
        }
        for(int j=0;j<n;j++){
            dp[0][j] = 1;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    
    }
};