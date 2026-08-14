class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> window;

        int left = 0;

        for (int right = 0; right < nums.size(); right++) {
            if (right-left+1 > k+1 ) {
                cout << nums[left] << endl;
                cout << nums[right] << endl;
                window.erase(nums[left]);
                left++;
            }
            if (window.count(nums[right]) > 0) {
                cout << nums[left] << endl;
                cout << nums[right] << endl;
                return true;
            }
        
            window.insert(nums[right]);
            cout << "r:" << nums[right] << endl;
            cout << "l: " << nums[left] << endl;
        }

        return false;
    }
};