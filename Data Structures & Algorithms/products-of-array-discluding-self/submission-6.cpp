class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(int(nums.size()));
        res[0] = 1;
        int prev = 1;
        for (int i = 0; i < nums.size(); i++) {
            res[i] = prev;
            prev *= nums[i];
        }

        int previous = nums[nums.size()-1];
        for (int i = nums.size()-2; i >= 0; i--) {
            res[i] *= previous;
            //cout << "res[i]: " << res[i] << endl;
            previous *= nums[i];
        }

        return res;

    }
};
