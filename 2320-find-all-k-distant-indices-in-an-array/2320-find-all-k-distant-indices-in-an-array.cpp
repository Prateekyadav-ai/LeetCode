class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
    set<int> result;
    int n = nums.size();

    for (int j = 0; j < n; ++j) {
        if (nums[j] == key) {
            int start = max(0, j - k);
            int end = min(n - 1, j + k);
            for (int i = start; i <= end; ++i) {
                result.insert(i);
            }
        }
    }

    // Convert set to vector
    return vector<int>(result.begin(), result.end());
}
};