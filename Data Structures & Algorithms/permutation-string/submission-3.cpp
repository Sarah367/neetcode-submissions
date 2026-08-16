class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int left = 0;

        unordered_map<char,int> freq1;
        for (char c : s1) {
            freq1[c]++;
        }
        unordered_map<char,int> freq2;
        for (int right = 0; right < s2.size(); right++) {
            cout << "left: " << s2[left] << endl;
            cout << "right: " << s2[right] << endl;
            
            freq2[s2[right]]++;
                

            
            if (right-left+1 == s1.size()) {
                cout << "IMHERE" << endl;
                if (freq2 == freq1) {
                    return true;
                } else {
                    cout << "s2[left]: " << s2[left] << endl;
                    freq2[s2[left]]--;
                    if (freq2[s2[left]] <= 0) {
                        cout << "im here erasing" << endl;
                        freq2.erase(s2[left]);
                    }
                    left++;
                }
            }
            
            
            


            
        }
        return false;


    }
};
