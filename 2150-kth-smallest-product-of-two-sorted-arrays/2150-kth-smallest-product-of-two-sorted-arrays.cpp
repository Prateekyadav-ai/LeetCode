class Solution {
public:
    long long countLessEqual(vector<int>& nums1, vector<int>& nums2, long long mid) {
        long long count = 0;
        int n = nums2.size();
        for (int i = 0; i < nums1.size(); i++) {
            long a = nums1[i];
            if (a > 0) {
                // binary search nums2[j] such that a * nums2[j] <= mid
                int l = 0, r = n - 1;
                while (l <= r) {
                    int m = (l + r) / 2;
                    if (a * (long long)nums2[m] <= mid)
                        l = m + 1;
                    else
                        r = m - 1;
                }
                count += l;
            } else if (a < 0) {
                int l = 0, r = n - 1;
                while (l <= r) {
                    int m = (l + r) / 2;
                    if (a * (long long)nums2[m] <= mid)
                        r = m - 1;
                    else
                        l = m + 1;
                }
                count += (n - l);
            } else {
                if (mid >= 0) count += n;
            }
        }
        return count;
    }

    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        long long left = -1e10, right = 1e10;
        long long ans = 0;
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (countLessEqual(nums1, nums2, mid) < k)
                left = mid + 1;
            else {
                ans = mid;
                right = mid - 1;
            }
        }
        return ans;
    }
};
