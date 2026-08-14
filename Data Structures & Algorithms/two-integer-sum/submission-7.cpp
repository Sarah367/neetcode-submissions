class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        std::unordered_map<int, int> freq;

        for (int num : nums) {
            freq[num]++;
        }

        // 7 <-- 
        // 7 - 4 == 3
        int nextNum = 0; 
        int start = 0;
        for (const auto& [num, count] : freq) {
            for (int i = 0; i < nums.size(); i++) {
                nextNum = target - nums[i]; 
                if (freq[nextNum] >= 1) {
                    start = i+1;
                    for (int j = start; j < nums.size(); j++) {
                        if (nums[j] == nextNum) {
                            res.push_back(i);
                            res.push_back(j);
                            return res;
                            
                        }
                    }
                    
                }
            }
            
        }

        return res;
    }
};
