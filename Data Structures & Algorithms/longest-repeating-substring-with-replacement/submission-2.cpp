class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int length = INT_MIN;
        int freqMax = 0;

        unordered_map<char, int> freq;
        for (int right = 0; right < s.size(); right++) {
            freq[s[right]]++;
            freqMax = max(freq[s[right]], freqMax);

            while ((right-left+1) - freqMax > k) {
                freq[s[left]]--;
                left++;

            }

            length = max(length, right-left+1);
        }

        return length;
    }
};
