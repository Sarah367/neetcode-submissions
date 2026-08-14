class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size()-1;
        int maxH = 0, area = 0;

        while (left < right) {
            int threshold = min(heights[left], heights[right]);

            area = (right-left) * threshold;
            maxH = max(maxH, area);

            if (heights[left] < heights[right]) {
                left++;
            } else if (heights[right] < heights[left]) {
                right--;
            } else {
                left++;
                right--;
            }




        }

        return maxH;
    }
};
