class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        auto total = nums1.size() + nums2.size();
        if (total & 1)
            return findK(nums1, nums2, total / 2);
        else
            return (findK(nums1, nums2, total / 2 - 1) + findK(nums1, nums2, total / 2)) * 0.5;
    }

    double findK(vector<int>& nums1, vector<int>& nums2, vector<int>::size_type k) {
        auto m = nums1.size(), n = nums2.size();
        auto p = k / 2, q = k - p;
        auto step = (k + 1) / 2;
        /*
        cout << endl << "[";
        for (auto num : nums1)
            cout << num << " ";
        cout << "] [";
        for (auto num : nums2)
            cout << num << " ";
        cout << "] " << k << endl;
        */
        while (true) {
            p = (p > m) ? m : p < 0 ? 0 : p;
            q = k - p;
            q = (q > n) ? n : q < 0 ? 0 : q;
            p = k - q;
            // cout << p << "+" << q << " step " << step << endl;
            // assert(p + q == k);
            if (p == m || (q < n && nums1[p] > nums2[q])) {
                if (p == 0 || nums1[p - 1] <= nums2[q])
                    return nums2[q];
                p -= step;
                q += step;
            } else if (q == n || nums1[p] < nums2[q]) {
                if (q == 0 || nums2[q - 1] <= nums1[p])
                    return nums1[p];
                p += step;
                q -= step;
            } else if (nums1[p] == nums2[q]) {
                return nums1[p];
            }
            step = (step + 1) / 2;
        }
    }
};