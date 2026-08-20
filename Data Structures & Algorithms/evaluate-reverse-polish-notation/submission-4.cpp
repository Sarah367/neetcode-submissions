class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> track;
        int res = 0;
        string validTokens = "+*-/";
        for (int i = 0; i < tokens.size(); i++) {
            if (validTokens.find(tokens[i]) != std::string::npos) {
                int number1 = track.back();
                track.pop_back();
                int number2 = track.back();
                track.pop_back();

                if (tokens[i] == "+") {
                    res = number1 + number2;
                    
                } else if (tokens[i] == "-") {
                    res = number2-number1;
                } else if (tokens[i] == "/") {
                    res = number2/number1;
                } else {
                    res = number2 * number1;
                }
                track.push_back(res);
            } else {
                track.push_back(stoi(tokens[i]));
            }


        }

        return track[0];



    }
};
