class Solution {
public:
    int appendCharacters(string s, string t) {
        int min = 0;
        int i = 0, j = 0;
        int start = 0; int minVal = 0;
        // coachingding
        while (i < s.size() && j < t.size()) {
            if (s[i] == t[j]) {

                j++;
            } 
            i++;
            
        }


        return t.size()-j;
    }
};