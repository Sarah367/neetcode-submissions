class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int res = 0;
        vector<int> track;
        set<string> operators = {"+", "-", "/", "*"};
        int prev = 0, index = 0;
        int final = 0; int cnt = 0;
        vector<int> easy;
        for (int i = 0; i < tokens.size(); i++) {
            if (operators.find(tokens[i]) != operators.end()) {
                int num1 = track.back();
                track.pop_back();

                int num2 = track.back();
                track.pop_back();

                int res; 
                if (tokens[i] == "+") {
                    res = num1+num2;
                } else if (tokens[i] == "-") {
                    res = num2-num1;
                } else if (tokens[i] == "*") {
                    res = num2 * num1;
                } else if (tokens[i] == "/") {
                    res = num2/num1;
                }
                track.push_back(res);
            } else {
                track.push_back(stoi(tokens[i]));
            }

        }

        return track.back();
    }
};
