class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> freq;
        int longestSub = 0;
        int maxFreq = 0; 
        int left=0;
        for (int right = 0; right < s.size(); right++) {
            freq[s[right]]++;

            if (maxFreq < freq[s[right]]) {
                maxFreq = freq[s[right]];
            }

            while ((right-left+1)-maxFreq > k) {
                freq[s[left]]--;
                left++;
                
            }








            longestSub = max(longestSub, right-left+1);
        }


        return longestSub;
    }
};
