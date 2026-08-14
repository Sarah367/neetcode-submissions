class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> mappingParan{
            {')', '('},
            {'}', '{'},
            {']', '['}
        };
        string res = "";
        for (int i = 0; i < s.size(); i++) {
            if (mappingParan.find(s[i]) != mappingParan.end()) {
                if (!res.empty() && res.back() == mappingParan[s[i]]) {
                    res.pop_back();
                } else {
                    return false;
                }


            } else {
                res.push_back(s[i]);
            }
        }

        if (res.empty()) {
            return true;
        }

        return false;
    }
};
