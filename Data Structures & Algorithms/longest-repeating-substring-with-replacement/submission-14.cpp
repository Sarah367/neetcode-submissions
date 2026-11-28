class Solution {
public:
    int characterReplacement(string s, int k) {
        // k = 2
        int maxFreq = 0;
        int left = 0;
        int longestString = 0;
        unordered_map<char,int> freq;
        for (int right = 0; right < s.size(); right++) {
            freq[s[right]]++;
            if (maxFreq < freq[s[right]]) {
                maxFreq = freq[s[right]];
            }
            
            while ((right-left+1)- maxFreq > k) {
                freq[s[left]]--;
                if (freq[s[left]] == 0) freq.erase(s[left]);
                left++;
            }

            longestString = max(longestString, right-left+1);
        }

        return longestString;


    }
};
