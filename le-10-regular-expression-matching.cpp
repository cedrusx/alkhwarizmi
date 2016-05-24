class Solution {
public:
    bool isMatch(string s, string p, string::size_type si = 0, string::size_type pi = 0) {
        // cout << s << "[" << si << "]\t" << p << "[" << pi << "]" << endl;
        if (si == s.size() && pi == p.size())
            return true;
        if (pi + 1 < p.size() && p[pi + 1] == '*') {
            if (isMatch(s, p, si, pi + 2))
                return true;
            if (si < s.size() && (p[pi] == '.' || p[pi] == s[si]))
                return isMatch(s, p, si + 1, pi);
            return false;
        }
        if (si == s.size() || pi == p.size())
            return false;
        if (p[pi] == '.' || p[pi] == s[si])
            return isMatch(s, p, si + 1, pi + 1);
        return false;
    }
};