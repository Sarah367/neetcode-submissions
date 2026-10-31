class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int left = 0;

 
        priority_queue<pair<int,int>> maxHeap;
        vector<int> res;
        for (int right = 0; right < nums.size(); right++) {
            maxHeap.push({nums[right], right});
            if (right-left+1 > k) {
                left++;
            }
            while (maxHeap.top().second < left) {
                maxHeap.pop();
                        
            }
            if (right-left+1 == k) {
                res.push_back(maxHeap.top().first);
            }
            //res.push_back(maxHeap.top().first);
            
            
            
            

            

        }
       

        return res;



    }
};
