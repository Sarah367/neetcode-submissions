class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> freq;

        for (char c : t) {
            freq[c]++;
        }
        int cnt = 0; int minimum = INT_MAX;
        string res = "";
        int left = 0;
        unordered_map<char,int> sFreq;
        int bestStart = 0;
        for (int right = 0; right < s.size(); right++) {
            if (freq.find(s[right]) != freq.end()) {
                sFreq[s[right]]++;
            }

            while(covers(sFreq, freq)) {
                if (right-left+1 < minimum) {
                    minimum = right-left+1;
                    bestStart = left;
                }

                if (freq.find(s[left]) != freq.end()) {
                    sFreq[s[left]]--;
                }

                if (freq[s[left]] == 0) {
                    sFreq.erase(s[left]);
                }


                left++;
            }


        }

        if (minimum == INT_MAX) {
            return "";
        }

        res = s.substr(bestStart, minimum);

        return res;
    }

    bool covers(unordered_map<char,int>& sFreq, unordered_map<char,int>& freq) {
        for (const auto& pair : freq) {
            if (sFreq[pair.first] < pair.second) return false;
        }
        return true;
    }


};
