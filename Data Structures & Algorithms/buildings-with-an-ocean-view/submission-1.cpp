class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        vector<int> res;
        int j = 0;
        stack<int> st;
        for (int i = heights.size()-1; i >= 0; i--) {
            int curr = heights[i];

            while (!st.empty() && st.top() < curr) {
                st.pop();
            }

            if (st.empty()) {
                res.push_back(i);
            }
            st.push(curr);
        }
        reverse(res.begin(), res.end());

        return res;


    }
};