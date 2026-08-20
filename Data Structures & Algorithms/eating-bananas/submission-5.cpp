class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // minimum eating speed
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int sum = 0, minEating=INT_MAX;
        while (low <= high) {
            int mid = (low+high)/2;
            //cout << "mid: " << mid << endl;
            for (int nums : piles) {
                //cout << "number: " << nums << endl;
                //cout << "sum: " << ceil(double(nums)/mid) << endl;
                sum += ceil(double(nums)/mid);
            }
            //cout << "FINAL SUM: " << sum << endl;
            if (sum > h) {
                low=mid+1;
            } 
            if (sum <= h) {
                
                minEating = min(minEating, mid);
                high=mid-1;
                
            }
            
            sum=0;


        }
        return minEating;

        

    }
};
