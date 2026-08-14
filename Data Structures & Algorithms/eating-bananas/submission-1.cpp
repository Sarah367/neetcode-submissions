class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int right = *max_element(piles.begin(), piles.end());
        int left = 1;
        int k = 0; int hours = 0;
        int res = right;
        while (left <= right) {
            k = (right+left)/2;
            hours = 0;
            for (int num : piles) {
                hours += ceil(double(num)/k);

            }
            if (hours <= h) {
                res = min(res,k);
                right = k -1;
            } else {
                left = k + 1;
            }
            
            
        }
        return res;


    }

};
