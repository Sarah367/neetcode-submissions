class Solution {
   public:
    string encode(vector<string>& strs) {
        string encoded_string = "";
        string encoded;
        if (strs.size() < 1) {
            return "empty";
        }
        int j = 0;
        for (int i = 0; i < strs.size(); i++) {
            int length = int(strs[i].size());
            encoded_string += (to_string(length) + "#" + strs[i]);
            
        }
        cout << "encoded string: " << encoded_string << endl;
        return encoded_string;
    }

    vector<string> decode(string s) {
        vector<string> decoded_strs;
        cout << "s: " << s << endl;
        int start = s[0];
        if (s == "empty") {
            return {};
        }
        int k = 0;
        int i = 0; int len = 0; string convertNums = "";
        while (i < s.size()) {
            k = i;
            k = s.find('#', i);
            convertNums = s.substr(i, k - i);
            // for (int j = i; j < k; j++) {
            //     convertNums += s[j];
            // }
            len = stoi(convertNums);
            cout << "len: " << len << std::endl;
            string words = s.substr(k+1, len);
            decoded_strs.push_back(words);


            i = k + len + 1;
            convertNums = "";
        }


        return decoded_strs;
    }
};
