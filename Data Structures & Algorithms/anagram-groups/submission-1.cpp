class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> groups;
        std::map<vector<int>, vector<string>> store;
        for (string w : strs) {
            vector<int> freq(26,0);
            for (char c : w) {
                freq[c-'a']++;
            }
            store[freq].push_back(w);
        }
        vector<string> exist;
        for (const auto& pair : store) {
            exist.clear();
            cout << " GROUP ";
            for (int i = 0; i < pair.second.size(); i++) {
                exist.push_back(pair.second[i]);
            }
            cout << endl;

            groups.push_back(exist);
        }
        
        return groups;
    }
};
