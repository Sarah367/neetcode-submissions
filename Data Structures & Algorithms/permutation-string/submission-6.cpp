class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        int left = 0;
        unordered_map<char, int> freq1;
        for (char c : s1) {
            freq1[c]++;
        }
        unordered_map<char, int> freqWindow;

        for (int right = 0; right < s2.size(); right++) {
            freqWindow[s2[right]]++;
            if (right - left + 1 == s1.size()) {
                if (freq1 == freqWindow) {
                    return true;
                }
                freqWindow[s2[left]]--;
                if (freqWindow[s2[left]] == 0) {
                    freqWindow.erase(s2[left]);
                }
                left++;
            }
        }

        return false;
    }
};
