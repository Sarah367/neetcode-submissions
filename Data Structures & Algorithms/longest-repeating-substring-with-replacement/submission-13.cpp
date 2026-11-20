class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int left = 0;
        int longest = INT_MIN;
        unordered_map<char,int> freq;
        int maxFreq = 0;
        
        for (int right = 0; right < s.size(); right++) {
            freq[s[right]]++;
            if (maxFreq < freq[s[right]]) {
                maxFreq = freq[s[right]];
            }
            //cout << "maxFreq: " << maxFreq << endl;
            //cout << "freq[right]: " << freq[s[right]] << endl;
            while (right-left+1 - maxFreq > k) {
                freq[s[left]]--;
                if (freq[s[left]] == 0) freq.erase(s[left]);
                left++;
                
                
            }

            longest = max(longest,right-left+1);

        }


        return longest;

    }
};
