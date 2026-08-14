class Solution {
public:
    int trap(vector<int>& height) {

        int leftMax = 0, rightMax = 0;
        int left = 0;
        int right = height.size()-1;
        int maxTotal = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] > leftMax) {
                    leftMax = height[left];
                } else {
                    maxTotal += leftMax - height[left];
                }
                left++;
                
            } else {
                
                    if (height[right] > rightMax) {
                        rightMax = height[right];
                    } else {
                        maxTotal += rightMax - height[right];
                    }
                
                right--;

            }
        }



        return maxTotal;
    }
};
