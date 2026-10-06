class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int minimum = *std::min_element(piles.begin(), piles.end());
        int maximum = *std::max_element(piles.begin(), piles.end());

        double left = 1;
        double right = maximum;
        int minRate = INT_MAX; int mid = 0;
        //cout << "minRate: " << minRate << endl;

        long long hours = 0;
        while (left <= right) {
            mid = ceil((left+right)/double(2));
            //cout << "mid: " << mid << endl;
            for (int i = 0; i < piles.size(); i++) {
                if (piles[i] >= mid) {
                    hours += ceil(double(piles[i]) / double(mid));
                    //cout << "piles[i]: " << piles[i] << endl;
                    //cout << "mid: " << mid << endl;
                    //cout << "hours: " << hours << endl;
                } else {
                    hours++;
                }
            }
            //cout << "hours: " << hours << endl;
            //cout << "mid: " << mid << endl;
            if (hours <= h) {
                minRate = min(minRate, mid);
                //cout << "minrate: " << minRate << endl;
                right = mid - 1;
            } else if (hours > h) {
                left = mid + 1;
            }

            hours = 0;
        }
        
        return minRate;
    }
};
