class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int cnt = 0;
        for (int i = 0; i < matrix.size(); i++) {
            cout << matrix[i][0] << endl;
            if (target < matrix[i][0]) {
                break;
            }
            cnt++;
        }
        cnt -= 1;
        if (cnt < 0) {
            return false;
        }
        int left = 0;
        int right = matrix[cnt].size()-1;
        cout << "cnt: " << cnt << endl;
        while (left <= right) {
            int mid = (left+right)/2;

            if (matrix[cnt][mid] == target) {
                return true;
            } else if (matrix[cnt][mid] < target) {
                left = mid+1;
            } else {
                right = mid-1;
            }

        }

        return false;
    }
};
