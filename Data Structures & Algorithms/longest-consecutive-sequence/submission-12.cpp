class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        unordered_map<int, int> freq;
        int cnt = 1;
        for (int num : nums) {
            freq[(num)]++;
        }
        int longest = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (freq.find(nums[i]-1) != freq.end()) {
                continue;
            }
            cnt=1;
            int start = nums[i]+1;
            
            while (freq.find(start) != freq.end()) {
                cnt++;
                start = start + 1;
            }
            cout << "longest: " << longest << endl;
            longest = max(longest, cnt);
        }

        return longest;
    }
};
