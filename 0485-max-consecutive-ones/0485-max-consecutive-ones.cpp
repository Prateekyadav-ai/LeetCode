class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxcount=0;
        int i=0;
        int count=0;
        while(i<nums.size()){
            if(nums[i]==1){
                count++;
                maxcount=max(maxcount,count);
            }
            else{
                count=0;
            }
            i++;
        }
        return maxcount;
    }
};