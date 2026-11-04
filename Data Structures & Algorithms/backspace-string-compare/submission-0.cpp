class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st;
        stack<char> stack;
        for (char c : s) {
            if (c != '#') {
                st.push(c);
            } else {
                if (!st.empty()) {
                    st.pop();
                }
                
            }
        }

        for (char c : t) {
            if (c != '#') {
                stack.push(c);
            } else {
                if (!stack.empty()) {
                    stack.pop();
                }
            }
        }

        return st == stack; 

    }
};
