// class Solution {
// public:
//     int solve(string& word1, string& word2, int i, int j,vector<vector<int>>&dp) {
//         // Base case
//         if (i == 0) return j;  // Need to insert all remaining characters of word2
//         if (j == 0) return i;  // Need to delete all remaining characters of word1
//         if(dp[i][j]!=-1){
//             return dp[i][j];
//         }
//         // If characters match, no operation needed
//         if (word1[i - 1] == word2[j - 1]) {
//             dp[i][j]= solve(word1, word2, i - 1, j - 1,dp);
//             return dp[i][j];
//         }

//         // Otherwise, consider insert, delete, and replace
//         int insertOp = solve(word1, word2, i, j - 1,dp);
//         int deleteOp = solve(word1, word2, i - 1, j,dp);
//         int replaceOp = solve(word1, word2, i - 1, j - 1,dp);

//         dp[i][j]= 1 + min({insertOp, deleteOp, replaceOp});
//         return dp[i][j];
//     }

//  int solvetab(string& word1, string& word2, int i, int j,vector<vector<int>>&dp) {
//         // Base case
//         if (i == 0) return j;  // Need to insert all remaining characters of word2
//         if (j == 0) return i;  // Need to delete all remaining characters of word1
//         if(dp[i][j]!=-1){
//             return dp[i][j];
//         }
//         // If characters match, no operation needed
//         if (word1[i - 1] == word2[j - 1]) {
//             dp[i][j]= solvetab(word1, word2, i - 1, j - 1,dp);
//             return dp[i][j];
//         }

//         // Otherwise, consider insert, delete, and replace
//         int insertOp = solvetab(word1, word2, i, j - 1,dp);
//         int deleteOp = solvetab(word1, word2, i - 1, j,dp);
//         int replaceOp = solvetab(word1, word2, i - 1, j - 1,dp);

//         dp[i][j]= 1 + min({insertOp, deleteOp, replaceOp});
//         return dp[i][j];
//     }

//     int minDistance(string word1, string word2) {
//         int n = word1.length(), m = word2.length();
//         vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
//         return solve(word1, word2, n, m,dp);
//     }
// };/
///////////////////////////////////////tabulation/////////////////////////////////////////////////////
// class Solution {
// public:
//     int minDistance(string word1, string word2) {
//         int n = word1.length();
//         int m = word2.length();

//         // Create dp table of size (n+1) x (m+1)
//         vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

//         // Base cases
//         for (int i = 0; i <= n; ++i) dp[i][0] = i; // delete all characters from word1
//         for (int j = 0; j <= m; ++j) dp[0][j] = j; // insert all characters into word1

//         // Fill the table
//         for (int i = 1; i <= n; ++i) {
//             for (int j = 1; j <= m; ++j) {
//                 if (word1[i - 1] == word2[j - 1]) {
//                     dp[i][j] = dp[i - 1][j - 1];  // characters match
//                 } else {
//                     dp[i][j] = 1 + min({
//                         dp[i - 1][j],     // delete
//                         dp[i][j - 1],     // insert
//                         dp[i - 1][j - 1]  // replace
//                     });
//                 }
//             }
//         }

//         return dp[n][m];
//     }
// };
////////////////////////////////////space optimization---------------------------------------------------
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        vector<int> prev(m + 1, 0), curr(m + 1, 0);

        // Base case: transforming empty word1 to word2
        for (int j = 0; j <= m; ++j) {
            prev[j] = j;
        }

        for (int i = 1; i <= n; ++i) {
            curr[0] = i;  // Base case: transforming word1[0..i] to empty word2

            for (int j = 1; j <= m; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    curr[j] = prev[j - 1];  // characters match
                } else {
                    curr[j] = 1 + min({
                        prev[j],     // delete
                        curr[j - 1], // insert
                        prev[j - 1]  // replace
                    });
                }
            }

            prev = curr;  // move current row to previous for next iteration
        }

        return prev[m];
    }
};


