class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char,int> tFreq;

        for (char c : t) {
            tFreq[c]++;
        }
        int minimum = INT_MAX;
        string res = "";
        int left = 0;
        unordered_map<char,int> sFreq;
        int cnt = 0;

        int bestLeft = 0;
        for (int right = 0; right < s.size(); right++) {
            if (tFreq.find(s[right]) != tFreq.end()) {
                sFreq[s[right]]++;
                
            }
            while (covers(sFreq, tFreq)) {
                if (right-left+1 <= minimum) {
                    bestLeft = left;
                    minimum = right-left+1; 
                }
                
                if (tFreq.find(s[left]) != tFreq.end()) {
                    sFreq[s[left]]--;
                    if (sFreq[s[left]] == 0) {
                        sFreq.erase(s[left]);
                    }
                }
                left++;
                
            }

        }
        if (minimum == INT_MAX) {
            return "";
        }
        res = s.substr(bestLeft, minimum);

        return res;
    }
    bool covers(unordered_map<char,int>& sFreq, unordered_map<char,int>& tFreq) {
        for (const auto& pair : tFreq) {
            if (sFreq[pair.first] < pair.second) return false;
        }
        return true;
    }
    
};
