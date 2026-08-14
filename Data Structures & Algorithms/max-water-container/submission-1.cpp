class Solution {
public:
    int maxArea(vector<int>& heights) {
        // index is width

        int left = 0; 
        int right = heights.size()-1;
        int height = 0; int width = 0;
        int max = 0; int prod = 0;
        while (left < right) {
            width = right-left;

            height = heights[left];
            if (height > heights[right]) {
                height = heights[right];
            }

            prod = height*width;
            
            if (heights[left] < heights[right]) {
                left++;
            } else if (heights[right] < heights[left]) {
                right--;
            } else {
                left++;
                right--;
            }
            if (max < prod) {
                max = prod;
            }
        }

        return max;
    }
};
