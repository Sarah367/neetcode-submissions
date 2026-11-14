class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int lastSeen = INT_MAX;
        bool inserted = false;
        vector<vector<int>> res;
        for (auto vec : intervals) {
            
            if (vec[0] >= newInterval[0] && inserted == false) {
                res.push_back(newInterval);
                res.push_back(vec);
                inserted = true;
            } else {
                res.push_back(vec);
            }

        }
        if (inserted == false) {
            res.push_back(newInterval);
        }
        vector<vector<int>> ans;
        ans.push_back(res[0]);
        for (auto vec : res) {
            if (ans.back()[1] >= vec[0]) {
                int newEndingVal = max(ans.back()[1], vec[1]);
                ans.back()[1] = newEndingVal;
                
            } else {
                ans.push_back(vec);
                
            }


        }


        return ans;
    }


};
