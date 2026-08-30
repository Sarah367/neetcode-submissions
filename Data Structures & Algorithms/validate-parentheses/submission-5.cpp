class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,int> mapping{
            {')', '('},
            {'}', '{'},
            {']', '['}
        };
        string res = "";

        for (int i = 0; i < s.size(); i++) {
            if (mapping.find(s[i]) != mapping.end()) {
                if (!res.empty() && res.back() == mapping[s[i]]) {
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
