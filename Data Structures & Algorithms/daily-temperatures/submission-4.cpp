class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size());

        stack<int> stk;

        for (int i = 0; i < temperatures.size(); i++) {
            while (!stk.empty() && temperatures[i] > temperatures[stk.top()]) {
                int index = stk.top();
                stk.pop();
                cout << "how many days: " << i - index << endl;
                res[index] = (i-index);
            }

            stk.push(i);
        }

        return res;
    }
};
