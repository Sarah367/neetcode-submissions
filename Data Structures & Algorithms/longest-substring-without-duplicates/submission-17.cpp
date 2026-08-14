class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        if (s.empty()) {
            return 0;
        }
        set<int> window;
        int length = INT_MIN;
        for (int right = 0; right < s.size(); right++) {
            if (window.find(s[right]) != window.end()) {
                while (s[left] != s[right]) {
                    window.erase(s[left]);
                    left++;
                }
                window.erase(s[left]);
                left++;
            }


            window.insert(s[right]);

            length = max(length,int(window.size()));
        }

        
        return length;
    } 
};
