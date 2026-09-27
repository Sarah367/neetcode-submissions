class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int left = 0;

        int cnt = 0; 
        double avg = 0;
        double sum = 0;
        for (int right = 0; right < arr.size(); right++) {
            if (right-left+1 > k) {

                avg = double(sum / k);
                if (avg >= threshold) {
                    cnt++;
                }
                sum -= arr[left];
                left++;
            }
            
            sum += arr[right];
        }
        if (double(sum/k) >= threshold) {
            cnt++;
        }

        return cnt;
    }
};