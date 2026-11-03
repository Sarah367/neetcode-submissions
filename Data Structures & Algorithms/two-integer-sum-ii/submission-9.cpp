class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size()-1;

        while (left < right) {
            
            int add = numbers[left] + numbers[right];
            if (add == target) {
                return {left+1, right+1};
            } else if (add > target) {
                right--;
            } else {
                left++;
            }



        }

        return {};
    }
};
