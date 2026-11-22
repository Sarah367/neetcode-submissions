class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        int start = 0;
        int longest = 0; int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            
            if (freq.find(nums[i]-1) == freq.end()) {
                start = nums[i];
            }

            while (freq.find(start) != freq.end()) {
                cnt++;
                start++;
            }

            longest = max(longest, cnt);
            cnt = 0;
        }


        return longest;
    }
};
