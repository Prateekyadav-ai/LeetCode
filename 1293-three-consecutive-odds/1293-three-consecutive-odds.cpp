class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n-2;i++){
          if((nums[i]&1!=0) && (nums[i+1]&1!=0) && (nums[i+2]&1!=0)){
            return true;
          }
          
        }
        return false;
    }
};