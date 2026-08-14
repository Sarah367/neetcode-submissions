class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        set<char> window;
        int length = INT_MIN;
        for (int right = 0; right < s.size(); right++) {

            while (window.find(s[right]) != window.end()) {
                window.erase(s[left]);
                left++;
                
            }   
            window.insert(s[right]);
            length = max(length, int(window.size()));
            
        }
        if (length == INT_MIN) {
            return 0;
        }
        return length;
    }
};
