class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int sum = 0;
        int length = nums.size()+1;
        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];
            cout << "SUM: " << sum << endl;

            while (sum >= target) {
                length = min(length, right-left+1);
                sum -= nums[left];
                left++;
                
            }
        }

        if (length == nums.size()+1) {
            return 0;
        }

        return length;



        

    }
};