class Solution {
public:
    bool isAnagram(string s, string t) {
        // s and t 
        if (s.length() != t.length()) {
            return false;
        }

        // std::unordered_map<int, int> freq;

        // for (char c : s) {
        //     freq[c]++;
        // }

        // std::unordered_map<int,int> freqSec;

        // for (char c : t) {
        //     freqSec[c]++;
        // }
        // sort string in alphabetical order.
        // identify characters and then take a look at their frequency count

        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());
        cout << s << endl;
        cout << t << endl;
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != t[i]) {
                return false;
            }
        }



        return true;

    }
};
