class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> output;
        deque<int> deq;
        int left = 0, right = 0;

        while (right < nums.size()) {
            while (!deq.empty() && nums[deq.back()] < nums[right]) {
                deq.pop_back();
            }

            deq.push_back(right);

            if ( deq.front() < left) {
                deq.pop_front();
            }

            if (right-left+1 == k) {
                output.push_back(nums[deq.front()]);
                //cout << "deq.front(): " << deq.front() << endl;
                left++;
            }
            right++;
        }



        return output;
    }
};
