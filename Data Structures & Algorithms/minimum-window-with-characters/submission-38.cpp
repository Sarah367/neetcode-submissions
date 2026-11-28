class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> sFreq;

        unordered_map<char,int> tFreq;

        for (char c : t) {
            tFreq[c]++;
        }

        int left = 0;
        int shortest = 0; int bestLeft = 0;
        int minLength = INT_MAX;
        for (int right = 0; right < s.size(); right++) {
            sFreq[s[right]]++;

            while (check(sFreq, tFreq)) {
                if (right-left+1 < minLength) {
                    minLength = right-left+1;
                    bestLeft = left; 
                } 

                sFreq[s[left]]--;
                if (sFreq[s[left]] == 0) sFreq.erase(s[left]);
                left++;

            }



        }
        if (minLength == INT_MAX) return "";
        string res = s.substr(bestLeft, minLength);

        return res;

    }

    bool check(unordered_map<char,int>& sFreq, unordered_map<char,int>& tFreq) {
        for (const auto& pair : tFreq) {
            if (sFreq[pair.first] < pair.second) return false;
        }
        return true; 
    }
};
