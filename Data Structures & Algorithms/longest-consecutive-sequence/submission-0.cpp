class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> freq;

        for (int num : nums) {
            freq[num]++;
        }
        int max = 0;
        for (const auto& pair : freq) {
            // [100,4,200,1,3,2]
            // [1,2,3,4] == 4
            if (freq.find(pair.first-1) == freq.end()) {
                int length = 1;
                int curr = pair.first;

                while (freq.find(curr+1) != freq.end()) {
                    length++;
                    curr++;
                }

                max = std::max(length, max);
                
            }
        }

        return max;
    }
};
