class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        bool window[128] = {false};
        if (s.empty()) {
            return 0;
        }

        int length= INT_MIN; 
        for (int right = 0; right < s.size(); right++) {
            if (window[s[right]]) {                
                while(s[left] != s[right]) {
                    window[s[left]] = false;
                    left++;
                }          
                window[s[left]]=false;
                left++;
            }

            window[s[right]] = true;
            length = max(right-left+1, length);

        }

       
        return length;


    } 
};
