class Solution {
public:
    int maxArea(vector<int>& heights) {
        // 2 pointers
        int left = 0;
        int right = heights.size()-1;
        int maxArea = 0;
        while (left <= right) {
            int width = right-left;

            int height = min(heights[right], heights[left]);

            int area = width * height;

            maxArea = max(area, maxArea);

            if (heights[left] <= heights[right]) {
                left++;
            } else if (heights[right] < heights[left]) {
                right--;
            }



        }

        return maxArea; 


    }
};
