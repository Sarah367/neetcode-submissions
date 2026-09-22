class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        
        
        for (string s : strs) {
            int count[26] = {};
            for (char c : s) {
                count[c-'a']++;
                
            }

            string key = "";
            for (int i = 0; i < 26; i++) {
                key += to_string(count[i]) + "#";
            }

            groups[key].push_back(s);
        }

        vector<vector<string>> res;

        for (const auto& pair : groups) {
            res.push_back(pair.second);
        }


        return res;
    }
};
