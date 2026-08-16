class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int left = 0;
        int max = 0;
        vector<int> res;

        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        vector<vector<int>> bucket(nums.size() + 1);
        for (const auto& pair : freq) {
            bucket[pair.second].push_back(pair.first);
        }

        for (int i = nums.size(); i >= 1; i--) {
            if (!bucket[i].empty()) {
                for (int num : bucket[i]) {
                    if (res.size() == k) {
                        return res;
                    }
                    res.push_back(num);
                    
                }
            }
        }

        return res;
    }
};
