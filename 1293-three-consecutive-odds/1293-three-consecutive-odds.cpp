class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n-2;i++){
          if((nums[i]%2!=0) && (nums[i+1]%2!=0) && (nums[i+2]%2!=0)){
            return true;
          }
          
        }
        return false;
    }
};