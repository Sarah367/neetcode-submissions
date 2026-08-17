class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0;
        int maxProfit = 0, profit = 0, maxi = 0, mini = 0;
        for (int right = 1; right < prices.size(); right++) {
            
            if (prices[right] <= prices[left]) {
                left=right;
            } else{
                maxi = prices[right];
                mini = prices[left];
            }
            profit = maxi-mini;

            maxProfit = max(profit, maxProfit);


            
        }
        if (maxProfit <= 0) {
            return 0;
        }
        return maxProfit;
    }
};
