class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int left = 0;
        vector<int> res;
        if (nums.size()==1) {
            return {nums[0]}; 
        }
        set<int> window; int maxNum = INT_MIN;
        unordered_map<int,int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        for (int right = 0; right < nums.size(); right++) {
            window.insert(nums[right]);

            if (right-left+1 == k) {
                for (int num : window) {
                    if (num > maxNum) {
                        maxNum = num;
                    }
                }

                
                res.push_back(maxNum);
                maxNum = INT_MIN; 
                freq[nums[left]]--;
                if (freq[nums[left]] == 0) {
                    window.erase(nums[left]);
                }

                left++;
            }
        }

        return res;


    }
};
