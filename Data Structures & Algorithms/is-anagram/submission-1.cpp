class Solution {
public:
    bool isAnagram(string s, string t) {
        // s and t 
        if (s.length() != t.length()) {
            return false;
        }

        std::unordered_map<char, int> freq;

        for (char c : s) {
            // ascii value
            freq[c - 'a']++;
        }
        // abc
        // 97 98 99 
        // bac
        // 98 97 99 

        for (char c : t) {
            freq[c-'a']--;
        }

        for (const auto& pair : freq) {
            if (pair.second != 0) {
                return false;
            }
        }

        return true;

    }
};
