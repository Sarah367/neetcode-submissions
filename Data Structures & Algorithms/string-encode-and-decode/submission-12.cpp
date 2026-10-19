class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_string = "";
        string res = "";
        int wordCount = 0;
        for (string s : strs) {
            for (char c : s) {
                wordCount++;
            }

            res += to_string(wordCount) + "#" + s;
            wordCount = 0;
        }

        std::cout << res << endl;
        return res;
    }

    vector<string> decode(string s) {
        cout << s << endl;
        vector<string> res;
        int i = 0;
        int numOfChars = 0;
        int debug = 0;
        while (i < s.size()) {
            cout << "i : " << i << endl;

            string numberOfChars = "";
            while (i < s.size() && s[i] != '#') {
                numberOfChars += (s[i]);
                i++;
            }
            if (numberOfChars != "") {
                numOfChars = std::stoi(numberOfChars);
            }
            
            string wordToExtract = s.substr(i+1, numOfChars);
            cout << "Word: " << wordToExtract << endl;
            res.push_back(wordToExtract);

            int iteration = i+numOfChars+1;
            if (iteration < s.size()) {
                i = iteration;
            } else {
                break;
            }
            numOfChars = 0;
        }

        return res;
    }
};
