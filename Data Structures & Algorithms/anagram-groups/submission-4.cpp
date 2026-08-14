class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> track;

        for (string s : strs) {
            int count[26] = {0};
            string key = "";
            for (char c : s) {
                count[c-'a']++;

            }
            for (int n : count) {
                key += to_string(n) + ",";
            }
            // append here?
            track[key].push_back(s);
        }

        vector<vector<string>> res;
        for (const auto& pair : track) {
            res.push_back(pair.second);
        }

        return res;
    }
};
