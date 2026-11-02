class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> sString;
        unordered_map<char,int> tString;

        for (char c : s) {
            sString[c]++;
        }

        for (char c : t) {
            tString[c]++;
        }

        if (sString == tString) {
            return true;
        }

        return false;
    }
};
