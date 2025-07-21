class Solution {
public:
    string makeFancyString(string s) {
        string res;
        for (int i = 0; i < s.length(); i++) {
            int n = res.size();
            if (n >= 2 && res[n-1] == s[i] && res[n-2] == s[i]) continue;
            res += s[i];
        }
        return res;
    }
};
