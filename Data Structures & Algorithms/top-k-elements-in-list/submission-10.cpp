class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

        unordered_map<int,int> freq;

        for (int num : nums) {
            freq[num]++;
        }

        for (const auto& pair : freq) {
            q.push({pair.second, pair.first});
            
            if (q.size() > k) {
                q.pop();
            }
        }

        vector<int> res;
        while (!q.empty()) {
            res.push_back(q.top().second);
            q.pop();
        }
        return res;
    }
};
