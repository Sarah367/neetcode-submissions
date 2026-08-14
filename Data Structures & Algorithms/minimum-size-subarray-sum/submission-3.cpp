class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int sum = 0;
        int length = INT_MAX;
        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];
            cout << "Sum: " << sum << endl;
            while (sum >= target) {
                cout << "sum in this case: " << sum << endl;
                length = min(right-left+1, length);
                cout << "length: " << length << endl;
                sum -= nums[left];
                left++;
            }
        }
        if (length == INT_MAX) {
            return 0;
        }

        return length;
    }
};