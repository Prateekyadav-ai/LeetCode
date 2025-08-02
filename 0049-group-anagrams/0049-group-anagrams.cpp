class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        unordered_map<string,vector<string>>mp;
        for(int i=0;i<strs.size();i++){
           string orginal=strs[i];
           string copy=orginal;
           sort(copy.begin(),copy.end());
           mp[copy].push_back(orginal);
        }
        for(auto i:mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};