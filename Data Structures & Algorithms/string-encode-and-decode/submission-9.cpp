class Solution {
public:
    string encode(vector<string>& strs) {
        
        string res = "";
        for (int i = 0; i < strs.size(); i++) {
            //cout << strs[i].size();
            res += to_string(strs[i].size()) + "#" + strs[i];
            
            
        }


        return res;
    }

    vector<string> decode(string s) {
        vector<string> result;
        string length = "";
        int i = 0;
        while (i < s.size()) {
            length = "";
            while (s[i] != '#') {
                length += s[i];
                i++;
            }
            cout << "i: " << i << endl;

            int sizeOfWord = std::stoi(length);
            cout << "size of word: " << sizeOfWord << endl;
            string newWord = s.substr(i+1, sizeOfWord);
            result.push_back(newWord);
            cout << "newWord: " << newWord << endl;

            i = i+1+sizeOfWord;
            
        }


        return result;
    }
};
