class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> sFreq;
        


        for (char c : s1) {
            sFreq[c]++;
        }
        int cnt = 0;
        for (int i = 0; i < s2.size(); i++) {
            if (sFreq.find(s2[i]) != sFreq.end()) {
                int j = i; 
                int matches = 0;
                unordered_map<char,int> s2Freq;
                int cnt = 0;
                while (cnt < s1.size() && j < s2.size()) {
                    if (sFreq.find(s2[j]) != sFreq.end()) {
                        s2Freq[s2[j]]++;
                        if (sFreq[s2[j]] == s2Freq[s2[j]]) {
                            matches++;
                        }
                    }
                    j++;
                    cnt++;

                }
                if (matches == sFreq.size()) return true;


            }



        }


       

        return false;
    }
};
