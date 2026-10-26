class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        unordered_map<int,int> freq;

        for (int num : nums) {
            freq[num]++;
        }
        int longestLen = 0, maximum = 1;
        //int start = nums[i];
    
        for (int i = 0; i < nums.size(); i++) {
            int start = nums[i];
            start--; // 0
            if (freq.find(start) != freq.end()) continue;
            cout << start << endl;
            start++; // 1
            while (freq.find(start) != freq.end()) {
                longestLen++;
                start++;
            }
            
            maximum = max(longestLen, maximum);
            longestLen = 0;
        }

        return maximum;
    }
};
