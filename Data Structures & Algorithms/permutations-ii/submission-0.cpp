class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        return helper(0, nums);
    }

    vector<vector<int>> helper(int i, vector<int>& nums) {
        if (i == nums.size()) {
            return {{}};
        }

        vector<vector<int>> resPerms;
        vector<vector<int>> perms = helper(i+1, nums);
        for (vector<int> p : perms) {
            for (int j = 0; j < p.size() + 1; j++) {
                //cout << p[j] << endl;
                // while (j+1 < p.size() && p[j] == p[j+1]) continue;
                
                vector<int> pCopy(p);
                pCopy.insert(pCopy.begin()+j, nums[i]);
                auto it = find(resPerms.begin(), resPerms.end(), pCopy);
                if (it != resPerms.end()) continue;
                resPerms.push_back(pCopy);
            }
        }
        return resPerms;
    }
};