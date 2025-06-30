class Solution {
public:
    int findLHS(vector<int>& nums) {
       unordered_map<int, int> freq;

        // Count frequency of each number
        for (int num : nums) {
            freq[num]++;
        }

        int maxLen = 0;
        // Iterate through the map using iterator and check for key + 1
        for (auto it = freq.begin(); it != freq.end(); ++it) {
            int key = it->first;
            int val = it->second;
            if (freq.count(key + 1)) {
                maxLen = max(maxLen, val + freq[key + 1]);
            }
        }

        return maxLen; 
    }
};