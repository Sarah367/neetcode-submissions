class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        int min = -1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i != j) {
                    if (nums[i] + nums[j] == target) {
                        if (i < j) {
                            res.push_back(i);
                            res.push_back(j);
                        }
                    }
                }
            }
        }


        return res;
    }
};
