class Solution {
public:
    int solve(string& word1, string& word2, int i, int j,vector<vector<int>>&dp) {
        // Base case
        if (i == 0) return j;  // Need to insert all remaining characters of word2
        if (j == 0) return i;  // Need to delete all remaining characters of word1
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        // If characters match, no operation needed
        if (word1[i - 1] == word2[j - 1]) {
            dp[i][j]= solve(word1, word2, i - 1, j - 1,dp);
            return dp[i][j];
        }

        // Otherwise, consider insert, delete, and replace
        int insertOp = solve(word1, word2, i, j - 1,dp);
        int deleteOp = solve(word1, word2, i - 1, j,dp);
        int replaceOp = solve(word1, word2, i - 1, j - 1,dp);

        dp[i][j]= 1 + min({insertOp, deleteOp, replaceOp});
        return dp[i][j];
    }

    int minDistance(string word1, string word2) {
        int n = word1.length(), m = word2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(word1, word2, n, m,dp);
    }
};
