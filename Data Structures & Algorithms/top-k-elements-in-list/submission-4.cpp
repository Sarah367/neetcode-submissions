class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        for (int num : nums) {
            freq[num]++;
        }

        vector<int> res;
        int maxi = 0, number = 0;

        while (k > 0) {
            for (const auto& pair : freq) {
                if (maxi < pair.second) {
                    maxi = pair.second;
                    number = pair.first;
                }
            }
            res.push_back(number);
            freq.erase(number);
            maxi = 0;
            k--;
        }

        return res;
    }
};
