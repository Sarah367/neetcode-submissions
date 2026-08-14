class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int left = 0;
        vector<int> res;
        if (nums.size()==1) {
            return {nums[0]}; 
        }

        std::vector<pair<size_t, int>> indexed_nums;
        set<int> window; int maxNum = 0;
        for (int right = 0; right < nums.size(); right++) {
            window.insert(nums[right]);

            if (right-left+1 == k) {
                cout << "IM HERE" << endl;
                cout << "nums[left]: " << nums[left] << endl;
                cout << "nums[right]: " << nums[right] << endl;
                std::vector<int> sorting = nums;
                sort(sorting.begin()+left, sorting.begin()+right+1);
                maxNum = sorting[right];
                cout << "maxNum: " << maxNum << endl;
                res.push_back(sorting[right]);

                

                

                
                cout << "unsorted nums[left]: " << nums[left] << endl;
                cout << "unsorted nums[right]: " << nums[right] << endl;

                left++;

            }
            
        }

        for (int i = 0; i < nums.size(); i++) {
            cout << "nums[i]: " <<nums[i] << endl;
        }
        return res;
       

    }
};
