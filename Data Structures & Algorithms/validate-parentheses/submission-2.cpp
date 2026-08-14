class Solution {
public:
    bool isValid(string s) {
        int cnt = 0;
        string res = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                res.push_back('(');
            } else if (s[i] == ')') {
                if (res.empty() || res.back() != '(') return false;
                res.pop_back();
            } else if (s[i] == '{') {
                res.push_back('{');
            } else if (s[i] == '}') {
                if (res.empty() || res.back() != '{') return false;
                res.pop_back();
            } else if (s[i] == '[') {
                res.push_back('[');
            } else if (s[i] == ']') {
                if (res.empty() || res.back() != '[') return false;
                res.pop_back();
            }
        }
        
        if (res.empty()) {
            return true;
        }

        return false;
    }
};
