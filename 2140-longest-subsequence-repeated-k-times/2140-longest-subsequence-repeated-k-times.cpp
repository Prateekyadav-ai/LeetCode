class Solution {
public:
    string longestSubsequenceRepeatedK(string s, int k) {
        int n0 = s.size();
        vector<int> arr(n0);
        for(int i = 0; i < n0; ++i) arr[i] = s[i] - 'a';
        
        array<int,26> cnt{};
        for(int c: arr) ++cnt[c];

        vector<int> cand;
        for(int c = 0; c < 26; ++c) if(cnt[c] >= k) cand.push_back(c);
        if(cand.empty()) return "";

        sort(cand.begin(), cand.end(), greater<int>());
        vector<int> filtered;
        filtered.reserve(n0);
        for(int c: arr) if(cnt[c] >= k) filtered.push_back(c);
        int n = filtered.size();

        vector<array<int,26>> nxt(n+1);
        for(int i = 0; i <= n; ++i) nxt[i].fill(n);
        for(int i = n-1; i >= 0; --i){
            nxt[i] = nxt[i+1];
            nxt[i][filtered[i]] = i;
        }

        int maxL = n / k;
        vector<int> res, best;
        res.reserve(maxL);
        int L;
        function<bool(int)> dfs = [&](int d){
            if(d == L) return true;
            for(int c: cand){
                res.push_back(c);
                int pos = 0;
                bool ok = true;
                for(int t = 0; t < k && ok; ++t){
                    for(int x: res){
                        pos = nxt[pos][x] + 1;
                        if(pos > n){ ok = false; break; }
                    }
                }
                if(ok && dfs(d+1)) return true;
                res.pop_back();
            }
            return false;
        };
        for(L = maxL; L > 0; --L){
            res.clear();
            if(dfs(0)){
                best = res;
                break;
            }
        }
        string ans;
        ans.reserve(best.size());
        for(int c: best) ans.push_back(char('a' + c));
        return ans;
    }
};