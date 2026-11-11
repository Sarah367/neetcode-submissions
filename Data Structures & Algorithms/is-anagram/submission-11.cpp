class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> sFreq;
        for (char c : s) {
            sFreq[c]++;
        }

        unordered_map<char,int> tFreq;
        for (char c : t) {
            tFreq[c]++;
        }


        if (sFreq == tFreq) return true;


        return false;
    }
};
