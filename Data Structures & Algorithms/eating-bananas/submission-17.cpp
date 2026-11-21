class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int minEatingRate = INT_MAX;
        int maxVal = *max_element(piles.begin(), piles.end());

        int left = 1;
        int right = maxVal;
        long long hours = 0;
        while (left <= right) {
            int mid = (left+right)/2;

            for (int num : piles) {
                int fullBites = num/mid;

                int leftover = num % mid;

                if (leftover != 0) {
                    hours += fullBites+1;

                } else {
                    hours += fullBites;
                }
            }
            cout << hours << endl;
            if (hours <= h) {
                minEatingRate = min(minEatingRate, mid);
                right = mid - 1;
            } else {
                left = mid+1;
            }
            hours = 0;

        }

        return minEatingRate;


    }
};
