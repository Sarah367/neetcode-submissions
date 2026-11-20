class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        
        string key = "";
        unordered_map<string, vector<string>> pairings;
        for (string s : strs) {
            key = "";
            int count[26] = {0};
            for (char c : s) {
                count[c-'a']++;
            }

            for (int num : count) {
                key += "#" + to_string(num);
            }
            //cout << "key: " << key << endl;        
            pairings[key].push_back(s); 
        }

        for (const auto& pair : pairings) {
            res.push_back({pair.second});
        }

        return res;
    }
};
