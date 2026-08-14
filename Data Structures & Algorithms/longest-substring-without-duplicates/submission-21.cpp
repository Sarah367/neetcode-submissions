class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int longest = 0;
        set<char> window;
        for (int right = 0; right < s.size(); right++) {
            // zxyz
            

            while (window.find(s[right]) != window.end()) {
                //cout << "s[right]: " << s[right] << endl;
                window.erase(s[left]);

                left++;
            }

            

            window.insert(s[right]);
            longest=max(longest,(right-left+1));
        }   

        return longest;

    }
};
