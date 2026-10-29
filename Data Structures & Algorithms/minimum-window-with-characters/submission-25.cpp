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
auto isGreaterOrEqual = [](const auto& sFreq, const auto& tFreq) {
    for (const auto& [ch, count] : tFreq) {
        auto it = sFreq.find(ch);
        if (it == sFreq.end() || it->second < count) {
            return false;
        }
    }
    return true;
};
        int bestLeft = 0;
        for (int right = 0; right < s.size(); right++) {
            if (tFreq.find(s[right]) != tFreq.end()) {
                sFreq[s[right]]++;
                
            }
            while (isGreaterOrEqual(sFreq, tFreq)) {
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
    
};
