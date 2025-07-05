class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        int maxfrq=0;
        for(auto i:mp){
            int maxi=0;
            if(i.first==i.second){
                maxi=i.first;
                maxfrq=max(maxfrq,maxi);
            }
        }
        if(maxfrq>0){
            return maxfrq;
        }
        return -1;
    }
};