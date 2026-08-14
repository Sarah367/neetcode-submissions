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

            auto it = find(numbers.begin()+1, numbers.end(), diff);
            cout << "IT: " << diff << endl;
            index = it - numbers.begin();
            if (it != numbers.end()) {
                return {left+1, index+1};
            }
          
            left++;
        }


        return {0,0};
    }
};
