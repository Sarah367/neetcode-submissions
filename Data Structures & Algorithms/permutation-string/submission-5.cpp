class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.size() < s1.size()) {
            return false;
        }
        int left = 0;
        unordered_map<char,int> freqS1;
        for (char c : s1) {
            freqS1[c]++;
        }
        int cnt = 0;
        unordered_map<char,int> freqS2;
        for (int right = 0; right < s2.size(); right++) {

            freqS2[s2[right]]++;
            if (right-left+1 == s1.size()) {
                if (freqS2 == freqS1) {
                    return true;
                }
                
                freqS2[s2[left]]--;
                if (freqS2[s2[left]] == 0) {
                    freqS2.erase(s2[left]);
                }
                left++;
            }
            

            




        }

        return false;


    }
};
