class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        int n = nums.size();
        vector<vector<int>> buckets(n+1);

        for (const auto& pair : freq) {
            buckets[pair.second].push_back(pair.first);
        }
        vector<int> res;
        for (int i = buckets.size()-1; i >= 0; i--) {
            for (int num : buckets[i]) {
                res.push_back(num);

                if (res.size() == k) {
                    return res;
                }


            }


        }

        return res;
    }
};
