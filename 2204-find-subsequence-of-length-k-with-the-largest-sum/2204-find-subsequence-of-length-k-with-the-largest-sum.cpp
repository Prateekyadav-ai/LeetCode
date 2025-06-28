class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        // Pair of value and original index
        vector<pair<int, int>> pairs;
        for (int i = 0; i < nums.size(); ++i) {
            pairs.push_back({nums[i], i});
        }

        // Sort by value descending to pick top k
        sort(pairs.begin(), pairs.end(), [](auto &a, auto &b) {
            return a.first > b.first;
        });

        // Select top k
        vector<pair<int, int>> selected(pairs.begin(), pairs.begin() + k);

        // Sort back by index to maintain original order
        sort(selected.begin(), selected.end(), [](auto &a, auto &b) {
            return a.second < b.second;
        });

        // Extract only the values
        vector<int> result;
        for (auto &p : selected) {
            result.push_back(p.first);
        }

        return result;
    }
};
