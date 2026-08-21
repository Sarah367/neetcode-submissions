class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0, right = nums.size()-1;

        int answer = INT_MAX;

        while (left <= right) {
            int mid = (left+right)/2;
            if (nums[left] <= nums[mid]) {
                answer = min(answer, nums[left]);
                left = mid+1;
            } else {
                answer = min(answer, nums[mid]);
                right = mid-1;
            }

        }

        return answer;
    }
};
