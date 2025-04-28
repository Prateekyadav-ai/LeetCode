class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long count = 0;
        long long sum = 0;
        int i = 0;
        
        for (int j = 0; j < nums.size(); ++j) {
            sum += nums[j];
            
            while (i <= j && sum * (j - i + 1) >= k) {
                sum -= nums[i];
                i++;
            }
            
            count += (j - i + 1);
        }
        
        return count;
    }
};
