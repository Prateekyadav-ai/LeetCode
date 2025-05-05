class Solution {
public:
    const int MOD = 1e9 + 7;

    int solve(int n, vector<int>& memo) {
        if (n == 0) return 1;
        if (n == 1) return 1;
        if (n == 2) return 2;
        
        if (memo[n] != -1) return memo[n];

        int k = (2LL * solve(n - 1, memo) % MOD + solve(n - 3, memo)) % MOD;
        return memo[n] = k;
    }

    int numTilings(int n) {
        vector<int> memo(n + 1, -1);
        return solve(n, memo);
    }
};
