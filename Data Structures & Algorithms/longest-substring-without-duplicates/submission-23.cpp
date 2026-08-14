class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int longest = 0;
        
        //unordered_set<char> window;
        bool seen[128] = {};
        for (int right = 0; right < s.size(); right++) {
            // zxyz
            while (seen[s[right]]) {
                seen[s[left]] = false;
                left++;
            }
            // while (window.find(s[right]) != window.end()) {
            //     window.erase(s[left]);

            //     left++;
            // }

            seen[s[right]] = true;

            // window.insert(s[right]);
            longest=max(longest,(right-left+1));
        }   

        return longest;

    }
};
