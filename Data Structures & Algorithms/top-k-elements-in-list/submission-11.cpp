class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;

        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }   
        vector<vector<int>> store(nums.size()+1);
        for (const auto& pair : freq) {
            store[pair.second].push_back(pair.first);
        }

        vector<int> res;
        for (int i = store.size()-1; i>=0; i--) {
            
            for (int st : store[i]) {
                if (res.size() < k) {
                    res.push_back(st);
                }
            }

        }

        return res;
        
    }
};
