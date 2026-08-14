class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
    vector<int> res;
    int start = 0;
    int prod = 1;
    while (res.size() < nums.size()) {
        for (int i = 0; i < nums.size(); i++) {
            if (i != start) {
                prod *= nums[i];
            }
        }
        cout << prod << endl;
        res.push_back(prod);
        prod = 1;
        start++;
    }


    return res;

    }
};
