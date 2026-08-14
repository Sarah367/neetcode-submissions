class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        std::unordered_set<int> window;

        int left = 0;
        int cnt=0, sum=0, avg=0;
        for (int right = 0; right < arr.size(); right++) {
            if (right-left+1 > k) {
                if (sum / k >= threshold) {
                    cnt++;
                }
                
                sum -= arr[left];
                window.erase(arr[left]);
                left++;
            }

            window.insert(arr[right]);
            sum += arr[right];
        }
        if (sum / k >= threshold) {
            cnt++;
        }

        return cnt;
    }
};