class Solution {
public:
    int characterReplacement(string s, int k) {
        int freqMax = 0;
        int left = 0;
        unordered_map<char,int> freq;
        int length = 0;
        for (int right = 0; right < s.size(); right++) {
            freq[s[right]]++;
            freqMax=max(freq[s[right]], freqMax);
            int distinct = (right-left+1) - freqMax;

            if (distinct > k) {
                freq[s[left]]--;
                left++;
            }


            length = max(length, (right-left+1));
        }   


        return length;
    }
};
