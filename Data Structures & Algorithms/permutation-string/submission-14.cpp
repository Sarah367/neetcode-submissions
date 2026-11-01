class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int left = 0;
        unordered_map<char,int> s1Freq;

        for (char c : s1) {
            s1Freq[c]++;
        }
        unordered_map<char,int> mainFreq;
        for (int right = 0; right < s2.size(); right++) {
           
            mainFreq[s2[right]]++;
            

            while (right-left+1 > s1.size()) {
                mainFreq[s2[left]]--;
                if (mainFreq[s2[left]] == 0) {
                    mainFreq.erase(s2[left]);
                } 
                left++;
                

            }
            if (mainFreq == s1Freq && mainFreq.size() == s1Freq.size()) return true;




        }

        return false;
    }
};
