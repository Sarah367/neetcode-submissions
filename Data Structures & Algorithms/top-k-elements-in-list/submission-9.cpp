class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        vector<vector<int>> bucket(nums.size()+1);

        for (int num : nums) {
            freq[num]++;
        }

        for (const auto& pair : freq) {
            bucket[pair.second].push_back(pair.first);
        }
        vector<int> res;
        for (int i = bucket.size()-1; i >= 0; i--) {
            for (int num : bucket[i]) {
                if (k > 0) {
                    res.push_back(num);
                    k--;
                }
            }
        }

        return res;
    }
};
