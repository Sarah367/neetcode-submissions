class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = nums.size()-1;
        int mid = 0;
        while (left < right) {
            mid = (left+right)/2;

            if (nums[mid] > nums[right]) {
                left = mid+1;
            } else {
                right = mid;
            }
        }

        int min_index = left;

        if (min_index == 0) {
            left = 0;
            right = n-1;
        } else if (target >= nums[0] && target <= nums[min_index-1]) {
            left = 0;
            right = min_index-1;
        } else {
            left = min_index;
            right = nums.size()-1;
        }
        while (left <= right) {
            mid = (left+right)/2;

            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid+1;
            } else {
                right = mid-1;
            }
        }

        return -1;
    }
};
