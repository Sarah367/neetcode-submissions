class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        int cnt = 0;
        for (string s : strs) {
            for (char c : s) {
                cnt++;    

            }
            res += to_string(cnt) + "#" + s;

            cnt = 0;
        }

        return res;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0;
        int howManyChars = 0;
        while (i < s.size()) {
            string nums = "";
            while (s[i] != '#') {
                nums += to_string(s[i] - '0');
                i++;

            }
            if (!nums.empty()) {
                howManyChars = std::stoi(nums);
            }
            howManyChars = std::stoi(nums);
            cout << "numbers: " << howManyChars << endl;
            i++; // start of word
            string word = s.substr(i, howManyChars);
            cout << "Word: " << word << endl;
            ans.push_back(word);    

            i += howManyChars; 
        }

        return ans;
    }
};
