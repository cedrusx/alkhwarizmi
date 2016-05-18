class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty())
            return s;
        string::const_iterator center, longest_begin = s.begin();
        string::size_type longest_size = 1;
        for (auto center = s.begin(); center < s.end() - 1
                && (s.end() - center) * 2 - 1 > longest_size; center++) {
            auto left = center, right = center;
            for (; right + 1 < s.end() && *(right + 1) == *right; right++);
            for (; left >= s.begin() && right < s.end() && *left == *right; left--, right++);
            if (--right - ++left + 1 > longest_size) {
                longest_size = right - left + 1;
                longest_begin = left;
            }
        }
        return s.substr(longest_begin - s.begin(), longest_size);
    }
};