class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> s1Freq;

        for (char c : s1) {
            s1Freq[c]++;
        }
        unordered_map<char,int> s2Freq;

        int left = 0;

        for (int right = 0; right < s2.size(); right++) {
            s2Freq[s2[right]]++;

            if (right-left+1 > s1.size()) {
                s2Freq[s2[left]]--;
                if (s2Freq[s2[left]] == 0) {
                    s2Freq.erase(s2[left]);
                }
                left++;

            }

            if (s1Freq == s2Freq) {
                return true;
            }
        }

        return false;
    }
};
