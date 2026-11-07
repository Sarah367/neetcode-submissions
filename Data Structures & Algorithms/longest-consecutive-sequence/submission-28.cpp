class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longestLen = 0;
        int maxLen = 0;
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (freq.find(nums[i]-1) != freq.end()) {
                continue;
            }

            int start = nums[i];
            cout << start << endl;

            while (freq.find(start) != freq.end()) {
                //cout << "START: "<< start << endl;
                longestLen++;
                start++;
            }
            //cout << "longest: " << longestLen << endl;
            
            maxLen = max(longestLen, maxLen);
            longestLen = 0;
        }

        return maxLen;

    }
};
