class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> freqS;
        unordered_map<char,int> freqT;

        for (char c : s) {
            freqS[c]++;
        }

        for (char c : t) {
            freqT[c]++;
        }

        if (freqT == freqS) {
            return true;
        }

        return false;
    }
};
