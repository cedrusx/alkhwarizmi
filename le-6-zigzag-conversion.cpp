// 20ms
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1)
            return s;
        string res;
        for (int row = 0; row < numRows; row++) {
            for (auto c = s.begin() + row; c < s.end(); c += (2 * numRows - 2)) {
                res.push_back(*c);
                if (row != 0 && row != numRows - 1 && c + 2 * (numRows - row - 1) < s.end())
                    res.push_back(*(c + 2 * (numRows - row - 1)));
            }
        }
        return res;
    }
};

// 16ms
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1)
            return s;
        auto size = s.size();
        string res(size, 0);
        string::size_type rid = 0;
        for (int row = 0; row < numRows; row++) {
            for (string::size_type sid = row; sid < size; sid += (2 * numRows - 2)) {
                res[rid++] = s[sid];
                if (row != 0 && row != numRows - 1 && sid + 2 * (numRows - row - 1) < size)
                    res[rid++] = s[sid + 2 * (numRows - row - 1)];
            }
        }
        return res;
    }
};