class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int minEatingRate = 0;

        int maxVal = *max_element(piles.begin(), piles.end());
    
        int left = 1;
        int right = maxVal;

        int calc = 0;
        long long cnt = 0; int hours = 0;
        while (left <= right) {
            int mid = (left+right)/2;
            //cout << "mid: " << mid << endl;
            for (int num : piles) {
                int fullBites = num / mid;
                int leftover = num % mid;

                if (leftover != 0) {
                    cnt += fullBites +1;
                } else {
                    cnt += fullBites;
                }

                
            }
            //cout << "CNT: " << cnt << endl;
            
            if (cnt <= h) {
                right=mid-1;
                hours = mid;

            } else if (cnt > h) {
                left=mid+1;
            }

            
            cnt = 0;
        }
        

        return hours;


    }
};
