class Solution {
public:
    int reverse(int x) {
        string s = to_string(x);
        std::reverse(s.begin() + (x < 0), s.end());
        try {
            return stoi(s);
        } catch (logic_error err) {
            return 0;
        }
    }
};