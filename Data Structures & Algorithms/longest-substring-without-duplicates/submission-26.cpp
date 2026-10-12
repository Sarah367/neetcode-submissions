class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;

        unordered_map<char, int> freq;
        int longestString = 0;
        for (int right = 0; right < s.size(); right++) {
            freq[s[right]]++;

            while (freq[s[right]] > 1) {
                freq[s[left]]--;
                if (freq[s[left]] == 0) {
                    freq.erase(s[left]);
                }
                
                left++;
            }


            longestString = max(longestString, right-left+1);

        }

        return longestString;


    }
};
