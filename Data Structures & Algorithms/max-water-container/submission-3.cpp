class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size()-1;

        int maximum = INT_MIN;
        //int area = 0;
        while (left < right) {
            int width = (right-left);
            int height = min(heights[left], heights[right]);

            int area = width * height;

            if (heights[left] <= heights[right]) {
                left++;
            } else {
                right--;
            }

            maximum = max(maximum, area);

        }

        return maximum;
    }
};
