class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;

            int left = i+1;
            int right = nums.size()-1;

            while (left < right) {
                sum = nums[i] + nums[left] + nums[right];
                if (sum > 0) {
                    right--;
                } else if (sum < 0) {
                    left++;
                } else {
                    res.push_back({nums[i], nums[right], nums[left]});
                    right--;
                    while (nums[right] == nums[right+1] && right > left) {
                        right--;
                    }
                    // left++;
                    // while (nums[left] == nums[left-1] && left < right) {
                    //     left++;
                    // }
                }


            }
        }

        return res;
    
    }
};
