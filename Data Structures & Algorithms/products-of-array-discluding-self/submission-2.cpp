class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> res(nums.size());
    int prefix = 1;
    // 1, 2, 4, 6
    for (int i = 0; i < nums.size(); i++) {
        res[i] = prefix; // updating the left [1, 1, 2, 8]
        prefix *= nums[i]; // 1, 2, 8

        // calculate the right hand side
        

    }

    int postfix = 1;
    for (int i = nums.size()-1; i >= 0; i--) {
        res[i] *= postfix; // 8, 12, 24, 48
        postfix *= nums[i]; // 6, 24, 48
    }



    return res;

    }
};
