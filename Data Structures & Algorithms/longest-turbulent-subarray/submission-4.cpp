class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int left = 0, cnt = 1;
        int length = 1;
        int prev = 0; int curr = 0;
        for (int right = 1; right < arr.size(); right++) {

            if (arr[right] > arr[right-1] && prev != 1) {
                curr = 1;
                cnt++;
            } else if (arr[right] < arr[right-1] && prev != -1) {
                curr = -1;
                cnt++;
            } else if (arr[right] == arr[right-1]) {
                curr = 2;
                cnt = 1;
            }
            if (prev == curr && prev != 2) {
                cnt = 2;
            }
            
            
            prev = curr;
            
            length = max(length, cnt);
        }

        return length;
    }
};