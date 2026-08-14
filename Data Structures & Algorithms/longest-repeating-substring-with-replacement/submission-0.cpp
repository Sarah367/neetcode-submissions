class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> freq;
        
        int left = 0, maxFreq = 0;
        int ans = INT_MIN;
        char freqChar = s[left]; int length = 0; int cnt = 0;
        for (int right = 0; right < s.size(); right++) {
            freq[s[right]]++;
            maxFreq = max(freq[s[right]], maxFreq);
            if ((right-left+1) - maxFreq > k) {
                freq[s[left]]--;
                left++;
                cout << "left: " << left << endl;
                cout << "s[left]: " << s[left] << endl;
                cout << "s[right]: " << s[right] << endl;
            }
           

            
            
            cout << "maxFreq: " << maxFreq << endl;
            cout << "right: " << right << endl;
            cout << "left: " << left << endl;
            ans = max(ans, right-left+1);
            cout << "ans: " << ans << endl;
        }


        return ans;

    }
};
