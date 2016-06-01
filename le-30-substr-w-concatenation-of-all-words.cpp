class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, unsigned int> unmatched_tmpl;
        for (auto word : words) {
            auto search = unmatched_tmpl.find(word);
            if (search != unmatched_tmpl.end())
                search->second++;
            else
                unmatched_tmpl[word] = 1;
        }
        vector<int> res;
        int len = words[0].size();
        int maxk = (int)s.size() - len * words.size();
        for (int k = 0; k <= maxk; k++) {
            unordered_map<string, unsigned int> unmatched = unmatched_tmpl;
            int p = k;
            string target = s.substr(p, len);
            while (!unmatched.empty()) {
                auto search = unmatched.find(target);
                if (search == unmatched.end()) break;
                if (search->second > 1)
                    search->second--;
                else
                    unmatched.erase(search);
                p += len;
                target = s.substr(p, len);
            }
            if (unmatched.empty()) res.push_back(k);
        }
        return res;
    }
};