class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int longestSub = 0;
        unordered_map<char, int> freq;
        int maxFreq = 0;
        for (int right = 0; right < s.size(); right++) {
            freq[s[right]]++;
            maxFreq = max(maxFreq, freq[s[right]]);

            while ((right-left+1)-maxFreq > k) {
                freq[s[left]]--;
                left++;
            }

            longestSub = max(longestSub, right-left+1);
        }
        return longestSub;
    }
};
