class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> stacks;
        int record = 0; int sum = 0; int doubleInt = 0;
        for (int i = 0; i < operations.size(); i++) {
            if (operations[i] == "+") {
                sum = stacks.back() + stacks[stacks.size()-2];
                cout << "sum: " << sum << endl;
                stacks.push_back(sum);
            } else if (operations[i] == "C") {
                stacks.pop_back();
            } else if (operations[i] == "D") {
                doubleInt = (stacks.back() * 2);
                stacks.push_back(doubleInt);
            } else {
                stacks.push_back(stoi(operations[i]));
            }

            
        }

        for (int num : stacks) {
            record += num;
        }
        cout << "RECORD: " << record << endl;

        return record;

    }
};