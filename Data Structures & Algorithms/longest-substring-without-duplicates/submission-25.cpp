class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        set<char> window;
        int longestString = 0;
        for (int right = 0; right < s.size(); right++) {
            while (window.count(s[right]) > 0) {
                // keep incrementing left until its no longer a duplicate.
                window.erase(s[left]);
                left++;
                
            }
            


            window.insert(s[right]);
            longestString = max(longestString, right-left+1);
        }

        return longestString;
    }
};
