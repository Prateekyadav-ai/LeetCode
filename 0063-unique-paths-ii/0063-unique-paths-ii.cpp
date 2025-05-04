class Solution {
public:
    int countPaths(int i, int j, int m, int n, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        // Out of bounds or obstacle
        if (i >= m || j >= n || grid[i][j] == 1) return 0;
        
        // Base case: reached destination
        if (i == m - 1 && j == n - 1) return 1;
        
        // Check memo table
        if (dp[i][j] != -1) return dp[i][j];
        
        // Move down and right
        dp[i][j] = countPaths(i + 1, j, m, n, grid, dp) + countPaths(i, j + 1, m, n, grid, dp);
        return dp[i][j];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // If start or end is blocked, no path
        if (grid[0][0] == 1 || grid[m - 1][n - 1] == 1) return 0;

        vector<vector<int>> dp(m, vector<int>(n, -1));
        return countPaths(0, 0, m, n, grid, dp);
    }
};
