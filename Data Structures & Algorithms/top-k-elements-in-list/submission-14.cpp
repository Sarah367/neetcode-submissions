class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;

        for (int num : nums) {
            freq[num]++;
        }
        int n = nums.size();
        vector<vector<int>> bucket(n+1);

        for (const auto& pair : freq) {
            bucket[pair.second].push_back(pair.first);
        }
        vector<int> res;

        for (int i= bucket.size()-1; i>=0; i--) {
            for (int bucket : bucket[i]) {
                res.push_back(bucket);

                if (res.size() == k) return res;        
            }
        }

        return res;
    }
};
