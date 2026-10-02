class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> stk;
        int res = 0;
        unordered_set<string> operators = {"+", "-", "*", "/"};
        for (int i = 0; i < tokens.size(); i++) {
            if (operators.find(tokens[i]) != operators.end()) {
                int numberOne = std::stoi(stk.top());
                stk.pop();
                int numberTwo = std::stoi(stk.top());
                stk.pop();
                if (tokens[i] == "*") {
                    res = numberOne * numberTwo;
                } else if (tokens[i] == "/") {
                    res = numberTwo / numberOne;
                } else if (tokens[i] == "-") {
                    res = numberTwo - numberOne;
                } else {
                    res = numberTwo + numberOne;
                }
                stk.push(to_string(res));
            } else {
                stk.push(tokens[i]);
            }


        }

        return std::stoi(stk.top());
    }
};
