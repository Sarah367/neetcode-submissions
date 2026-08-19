class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        int cnt = 0, maxLength = 0;
        for (int i = 0; i < nums.size(); i++) {
            
            if (freq.find(nums[i]-1) != freq.end()) {
                //cout << "nums[i]: " << nums[i] << endl;
                continue;
            }
            int compare = nums[i];
            while (freq.find(compare) != freq.end()) {
                cnt++;
                compare++;
            }
            
            maxLength = max(maxLength,cnt);
            cnt = 0;
        }
        return maxLength;
    }
};
