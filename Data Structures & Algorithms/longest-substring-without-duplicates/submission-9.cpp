class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        unordered_set<int> window;
        if (s.empty()) {
            return 0;
        }
        int length= INT_MIN; 
        for (int right = 0; right < s.size(); right++) {
            if (window.find(s[right]) != window.end()) {
                
                cout << "length: " << length << endl;
                //window.erase(s[left]);
                left++;
                right=left;
                window.clear();
                
            }
            cout << "s right: " << s[right] << endl;
            window.insert(s[right]);
            length = max(int(window.size()), length);
        }

       
        return length;


    } 
};
