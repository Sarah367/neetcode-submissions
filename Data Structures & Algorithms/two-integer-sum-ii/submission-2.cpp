class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int> freq;
        
        int left = 0; 
        //int right = numbers.size()-1;
        int diff = 0;
        int index = 0;
        while (left < numbers.size()) {
            diff = target - numbers[left];
            cout << "IM HERE" << endl;
            auto it = find(numbers.begin(), numbers.begin() + left, diff);
            //cout << "IT: " << diff << endl; 
            index = it - numbers.begin();
            if (it == numbers.begin() + left) {
                it = find(numbers.begin() + left+1, numbers.end(), diff);
                if (it != numbers.end()) {
                    index = it -numbers.begin();
                    return {left+1, index+1};
                }
            }
          
            left++;
        }


        return {0,0};
    }
};
