class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>> buckets(nums.size()+1);

        unordered_map<int, int> freq;

        for (int num : nums) {
            freq[num]++;
        }

        for (const auto& pair : freq) {
            buckets[pair.second].push_back(pair.first);
        }
        vector<int> res;
        while (k > 0) {
            for (int i = buckets.size()-1; i >= 0; i--) {
                for (int num : buckets[i]) {
                    if (res.size() == k) {
                        return res;
                    }
                    res.push_back(num);
                }
                
            }
        }
        return res;
        // unordered_map<int, int> freq;

        // for (int num : nums) {
        //     freq[num]++;
        // }

        // vector<int> res;
        // int maxi = 0, number = 0;

        // while (k > 0) {
        //     for (const auto& pair : freq) {
        //         if (maxi < pair.second) {
        //             maxi = pair.second;
        //             number = pair.first;
        //         }
        //     }
        //     res.push_back(number);
        //     freq.erase(number);
        //     maxi = 0;
        //     k--;
        // }

        // return res;
    }
};
