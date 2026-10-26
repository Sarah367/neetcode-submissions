class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        string operators = "+-*/";
        for (int i = 0; i < tokens.size(); i++) {
            if (!st.empty() && operators.find(tokens[i]) != std::string::npos) {
                int num1 = stoi(st.top());
                //cout << "num1: " << num1 << endl;
                st.pop();
                int num2 = stoi(st.top());
                //cout << "num2: " << num2 << endl;
                st.pop();
                int res = 0;
                if (tokens[i] == "*") {
                    res = num1 * num2;
                } else if (tokens[i] == "/") {
                    res = num2 / num1;
                } else if (tokens[i] == "-") {
                    res = num2 - num1;
                } else if (tokens[i] == "+") {
                    res = num2 + num1;
                }
                //cout << "res: " << res << endl;
                st.push(to_string(res));

            } else {
                st.push(tokens[i]);
            }
            

        }


        return stoi(st.top());
    }
};
