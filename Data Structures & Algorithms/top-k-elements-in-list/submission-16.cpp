class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> maxHeap;

        unordered_map<int,int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        for (const auto& pair : freq) {
            maxHeap.push({pair.second, pair.first});
        }
        vector<int> res;
        while (res.size() != k) {
            int val = maxHeap.top().second;
            res.push_back(val);
            maxHeap.pop();
        }

        return res;

    }
};
