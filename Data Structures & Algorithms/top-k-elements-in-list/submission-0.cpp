class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::map<int,int> freq;

        for (int num : nums) {
            freq[num]++;
        }
        // value: 1, 1
        // value: 2, 2
        int max = -1;
   
   
        vector<int> res;
        int val = 0;
    while (k > 0) {
        for (const auto& pair : freq) {
            if (max < pair.second) {
                max = pair.second;
                val = pair.first;
            }
        }
        res.push_back(val);
        freq.erase(val);
        max = 0;
        std::cout << val << std::endl;
        k--;
    }



        

        return res;

    }
};
