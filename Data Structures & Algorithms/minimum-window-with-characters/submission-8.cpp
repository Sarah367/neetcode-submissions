class Solution {
public:
    string minWindow(string s, string t) {
        int left = 0;
        if (t.size() > s.size()) {
            return "";
        }
        map<char,int> freq;

        for (char c : t) {
            freq[c]++;
        }
        string newStr = "";
        map<char,int> freqWindow;
        int length = 0; int prevLength = 0;
        string res = ""; int currLength = 0;
        string extra = "";
        for (int right = 0; right < s.size(); right++) {
            if (freq.contains(s[right])) {
                map<char,int> duplicate(freq);
                newStr = "";
                while (!duplicate.empty() && right < s.size()) {
                    if (duplicate.contains(s[right])) {
                        duplicate[s[right]]--;                        
                    } 
                    
                    if (duplicate[s[right]] == 0) {
                        duplicate.erase(s[right]);
                    }
                    newStr += s[right];
  
                    right++;
                }
                currLength = newStr.size();
                if (!duplicate.empty()) {
                    continue;
                }
                
                if (prevLength != 0 && currLength < prevLength && currLength >= t.size()) {
                    res = newStr;
                    prevLength = newStr.size();
                } else if (prevLength == 0 && currLength >= t.size()) {
                    res = newStr;
                    prevLength = newStr.size();
                }


                left++;
                right = left-1;

            }


        }
        

        return res;
    }
};
