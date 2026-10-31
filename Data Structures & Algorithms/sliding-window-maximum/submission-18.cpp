class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int left = 0;

        vector<int> res;

        int maximum = 0;
        deque<int> dq;

        for (int right = 0; right < nums.size(); right++) {
            while (!dq.empty() && nums[dq.back()] < nums[right]) {
                dq.pop_back(); // this actually gets the maximum;
            }

            dq.push_back(right);

            if (right-left+1 == k) {
                res.push_back(nums[dq.front()]); // dq.front() will always be holding the maximum
                if (dq.front() == left) {
                    dq.pop_front();
                }
                left++;
            }


        }

        return res;
    }
};
