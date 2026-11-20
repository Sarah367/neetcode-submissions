class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        unordered_map<int,int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        for (const auto& pair : freq) {
            minHeap.push({pair.second, pair.first});
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        vector<int> res;
        while (!minHeap.empty()) {
            res.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return res; 
    }
};
