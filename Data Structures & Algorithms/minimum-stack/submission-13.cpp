class MinStack {
public:
    stack<int> minStack;
    stack<int> st;
    MinStack() {
        
    }
    
    void push(int val) {
        if (!minStack.empty()) {
            int compare = minStack.top();
            if (val <= compare) {
                minStack.push(val);
            }
        } else {
            minStack.push(val);
        }

        st.push(val);
    }
    
    void pop() {
        int value = st.top();
        if (value == minStack.top()) {
            minStack.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
