class Solution {
public:
    vector<string> result;    
    void dfs(string current, int n) {
        if (current.length() == n) {
            result.push_back(current);
            return;
        }       
        for (char c : {'a', 'b', 'c'}) {
            if (current.empty() || current.back() != c) {
                dfs(current + c, n);
            }
        }
    }
    string getHappyString(int n, int k) {
        dfs("", n);
        if (k > result.size()) return "";
        return result[k - 1];
    }
};
