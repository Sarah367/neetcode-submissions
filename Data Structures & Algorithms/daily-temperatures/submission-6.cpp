class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(),0);
        stack<int> st;
        for (int i = 0; i < temperatures.size(); i++) {
            while (!st.empty() && temperatures[st.top()] < temperatures[i]) {
                int index = st.top();
                st.pop();

                int numOfDays = i - index;
                res[index] = numOfDays;
            }


            st.push(i);

        }
        return res;
    }
};
