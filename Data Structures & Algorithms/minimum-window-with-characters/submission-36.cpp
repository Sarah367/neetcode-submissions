class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";
        unordered_map<char,int> freqT;

        for (char c : t) {
            freqT[c]++;
        }
        unordered_map<char,int> compare;
        int left = 0;
        int minimum = s.size()+1;
        string res = ""; int bestLeft = INT_MIN;
        for (int right = 0; right < s.size(); right++) {
            if (freqT.find(s[right]) != freqT.end()) {
                compare[s[right]]++;
            }

            while (check(compare, freqT)) {
                if (right-left+1 < minimum) {
                    minimum = right-left+1;
                    bestLeft = left; 
                }
                
                if (freqT.find(s[left]) != freqT.end()) {
                    compare[s[left]]--;
                    if (compare[s[left]] == 0) compare.erase(s[left]);
                }
                
                
                left++;


            }

        }
        if (bestLeft == INT_MIN) {
            return "";
        }
        string bestString = s.substr(bestLeft, minimum);


        return bestString;


    }

    bool check(unordered_map<char,int>& compare, unordered_map<char,int>& freqT) {
        for (const auto& pair : freqT) {
            if (compare[pair.first] < pair.second) return false;
        }
        return true;
    }
};
