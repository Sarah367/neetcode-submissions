class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0;
        int maxProf = 0, mini = 0, maxi = 0, profit = 0;
        for (int right = 1; right < prices.size(); right++) {
            if (prices[right] < prices[left]) {
                left = right;
            }
            maxProf= max(maxProf, prices[right] - prices[left]);

        }

        return maxProf;

    }
};
