class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0, nse = 0,index=0, pse=0;
        // nse (next smaller element) and pse (previous smaller element)
        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                index = st.top();
                st.pop();

                nse = i;
                pse = st.empty() ? -1 : st.top();

                int area = heights[index] * (nse-pse-1);

                maxArea = max(area, maxArea);
            }

            st.push(i);
        }

        while (!st.empty()) {
            nse = heights.size();
            index = st.top();
            st.pop();

            pse = st.empty() ? -1 : st.top();

            maxArea = max(maxArea, (nse-pse-1) * heights[index]);
        }

        return maxArea;

    }
};
