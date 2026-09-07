class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> groups;
        
        
        vector<vector<string>> res;
        for (string s : strs) {
            vector<int> count(26,0);
            string key = "";
            for (char c : s) {
                count[c-'a']++;
            }
            for (int num : count) {
                key += to_string(num) + "#";
            }
            groups[key].push_back(s);
            
            
        }

        
        for (const auto& pair : groups) {
            res.push_back(pair.second);
        }


        return res;
    }
};
