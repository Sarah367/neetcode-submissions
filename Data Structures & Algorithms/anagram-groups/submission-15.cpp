class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> store;

        for (string s : strs) {
            string key = "";
            int count[26] = {0};
            for (char c : s) {
                count[c-'a']++;
            }

            for (int c : count) {
                key += "#" + to_string(c);
            }
            //cout << "key: " << key << endl;
            store[key].push_back(s);        
        }
        vector<vector<string>> res;
        for (const auto& pair : store) {
            res.push_back(pair.second);
        }


        return res;
    }
};
