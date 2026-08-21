class Solution {
public:
    int findMin(vector<int> &nums) {
        
        int left = 0;
        int right = nums.size()-1;
        int mid = 0;
        
        while (left < right) {
            mid = (right+left)/2;

            if (nums[left] > nums[right]) {
                left++;
            } else if (nums[right] > nums[left]) {
                right=mid;
            }


        }
        return nums[left];


    }
};
