class Solution {
public:
   long long solve(vector<int>&nums,int k){
    long long count=0;
    int i=0;
    int j=nums.size()-1;
    while(i<j){
        if(nums[i]+nums[j]<=k){
            count=count+j-i;
            i++;
        }
        else{
            j--;
        }
    }
    return count;
   }
  
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        return solve(nums,upper)-solve(nums,lower-1);
    }
};