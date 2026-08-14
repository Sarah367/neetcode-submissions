class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;

        int left = 0, sum = 0;
        int maxi = 0, mini = 0;
        for (int right = 1; right < prices.size(); right++) {
            if (prices[right] <= prices[left]) {
                left=right;
            }
            if (prices[right] > prices[left]) {
                maxi = prices[right];
                mini = prices[left];
            }
            sum = maxi - mini;
            
            profit = max(profit, sum);
        }

        if (profit <= 0) {
            return 0;
        }

        return profit;
    }
};
