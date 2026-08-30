class MinStack {
public:
    stack<int> stk;
    stack<int> minStk;
    MinStack() {
        
    }
    
    void push(int val) {
        if (minStk.empty()) {
            minStk.push(val);
        } else if (!minStk.empty() && val <= minStk.top()) {
            minStk.push(val);
        }


        stk.push(val);
    }
    
    void pop() {
        if (!minStk.empty() && stk.top() == minStk.top()) {
            minStk.pop();
        }
        if (!stk.empty()) {
            stk.pop();
        }
        
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minStk.top();
    }
};
