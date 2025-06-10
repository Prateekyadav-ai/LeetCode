class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        int maxi=INT_MIN;
        int mini=INT_MAX;
        for(auto i:mp){
            if(maxi<i.second && (i.second%2)==1){
                maxi=i.second;
            }
        }
        for(auto i:mp){
            if(mini>i.second&& (i.second%2)==0){
                mini=i.second;
            }
        }
        return maxi-mini;
    }
};