class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        int l = 0, r = height.size() - 1;
        while (l < r) {
            if (height[l] < height[r]) {
                res = std::max(res, height[l] * (r - l));
                for (int k = l; l < r && height[l] <= height[k]; l++);
            } else {
                res = std::max(res, height[r] * (r - l));
                for (int k = r; l < r && height[r] <= height[k]; r--);
            }
        }
        return res;
    }
};