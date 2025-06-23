class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
       vector<pair<int, int>> v; 
       for(int i=0;i<nums.size();i++){
        int index=i;
        int value=nums[i];
        v.push_back({value,index});
       }
       sort(v.begin(),v.end());
       int s=0;
       int e=nums.size()-1;
       while(s<e){
        int sum=v[s].first+v[e].first;
        if(sum==target){
        ans.push_back(v[s].second);
         ans.push_back(v[e].second);
         return ans;
        }
        if(sum>target){
            e--;
        }
        else{
            s++;
        }
       }
     ans.push_back(-1);
     ans.push_back(-1);
     return ans;
    }
};