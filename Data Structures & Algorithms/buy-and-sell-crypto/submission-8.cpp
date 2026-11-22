class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0;
        int maxProf = 0;
        for (int right = 0; right < prices.size(); right++) {
            if (prices[right] < prices[left]) {
                left = right;
            }
            maxProf = max(maxProf, prices[right]-prices[left]);

        }

        return maxProf;
    }
};
