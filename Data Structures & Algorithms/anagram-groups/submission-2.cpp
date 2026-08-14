class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> track;

        for (string s : strs) {
            vector<int> count(26,0);
            
            for (char c : s) {
                count[c-'a']++;

            }
            // append here?
            track[count].push_back(s);
        }

        vector<vector<string>> res;
        for (const auto& pair : track) {
            res.push_back(pair.second);
        }

        return res;
    }
};
