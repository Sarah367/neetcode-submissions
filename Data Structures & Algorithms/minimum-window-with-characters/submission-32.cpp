class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> sFreq;
        unordered_map<char,int> tFreq;
        for (char c : t) {
            tFreq[c]++;
        }
        string shortest = "";
        int minimumWindow = s.size();
        int left = 0;
        int bestStart = 0;
        bool flag = false;
        
        for (int right = 0; right < s.size(); right++) {
            sFreq[s[right]]++;

            while (check(sFreq, tFreq)) {
                flag = true;
                if (right-left+1 < minimumWindow) {
                    bestStart = left; 
                    minimumWindow = right-left+1;
                }
                
                sFreq[s[left]]--;
                if (sFreq[s[left]] == 0) sFreq.erase(s[left]);
                left++;

            }



        }
        if (!flag) return ""; 
       // cout <<  "minWindow: " << minimumWindow << endl;

        shortest = s.substr(bestStart, minimumWindow);


        return shortest;

        
    }

    bool check(unordered_map<char,int>& sFreq, unordered_map<char,int>& tFreq) {
        for (const auto& pair : tFreq) {
            if (sFreq[pair.first] < pair.second) return false;
        }
        return true;
    }
};
