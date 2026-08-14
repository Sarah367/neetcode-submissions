class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()){
            return false;
        }
        unordered_map<char,int> freqS;

        unordered_map<char,int> freqT;

        for (char c : s) {
            freqS[c]++;
        }

        for (char c : t) {
            freqT[c]++;
        }

        for (int i = 0; i < s.size(); i++) {
            if (freqS[s[i]] != freqT[s[i]]) {
                return false;
            }
        }
        return true;

    }
};
