class Solution {
public:
    int myAtoi(string str) {
        int res = 0;
        int sign = 1;
        string::size_type id = 0;
        for (; id < str.size() && str[id] == ' '; id++);
        if (id < str.size() && (str[id] == '+' || str[id] == '-')) {
            if (str[id] == '-')
                sign = -1;
            id++;
        }
        for (; id < str.size() && str[id] >= '0' && str[id] <= '9'; id++) {
            unsigned long long res_new = 10 * (unsigned long long)res + (str[id] - '0');
            if (res_new > std::numeric_limits<int>::max()) // overflow
                return sign > 0 ? std::numeric_limits<int>::max() : std::numeric_limits<int>::min();
            res = res_new;
        }
        return sign * res;
    }
};