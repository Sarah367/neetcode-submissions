class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        int left = 0;
        int right = nums.size()-1; 
        int i = 0; vector<int> track;
        int index = 0; int j = 0; int cnt = 0;
        while (i < nums.size() && index < nums.size()) {
            if (nums[i] != val) {
                
                nums[index] = nums[i];
                index++;
                cnt=0;
                k++;
            } 
            i++;
           
            
        }
        return k;

    }
};