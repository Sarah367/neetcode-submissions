class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char> mapValid =
        {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        stack<char> stk;
        for (int i = 0; i < s.size(); i++) {
            if (mapValid.find(s[i]) != mapValid.end()) { // }]
                if (!stk.empty() && mapValid[s[i]] == stk.top()) { // { == {
                    stk.pop(); // ([
                } else {
                    return false;
                }
            } else {
                stk.push(s[i]); // ([{
            }

            
        }

        if (stk.empty()) {
            return true;
        }

        return false;

    }
};
