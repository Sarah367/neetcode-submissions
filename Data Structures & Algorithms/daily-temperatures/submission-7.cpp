class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        stack<int> st;

        for (int i = 0; i < temperatures.size(); i++) {
            while (!st.empty() && temperatures[st.top()] < temperatures[i]) {
                int val = st.top();
                cout << "val: " << val << endl;
                st.pop();
                cout << "i- val: " << i-val << endl;
                res[val] = abs(i - val);
            }

            st.push(i);
        }

        return res;
    }
};
