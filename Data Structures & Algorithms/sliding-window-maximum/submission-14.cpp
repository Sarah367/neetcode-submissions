class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int left = 0;
        vector<int> maxWindow; 
        deque<int> dq;
        int maximum = 0;
        for (int right = 0; right < nums.size(); right++) {
            while (!dq.empty() && nums[dq.back()] < nums[right]) {
                dq.pop_back();


            }
            dq.push_back(right);


            if (right-left+1 == k) {
                //cout << "max: " << dq.front() << endl;
                maxWindow.push_back(nums[dq.front()]);
                if (dq.front() == left) {
                    dq.pop_front();
                }
                left++;
            }
            

            
        }

        return maxWindow;
    }
};
