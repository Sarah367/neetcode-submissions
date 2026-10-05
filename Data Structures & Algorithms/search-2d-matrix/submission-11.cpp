class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left = 0;
        int right = matrix.size()-1;

        int row = -1;
        while (left <= right) {
            int mid = (left+right)/2;
            if (matrix[mid][0] < target) {
                row = mid;
                left = mid + 1;
            } else if (matrix[mid][0] > target) {
                right = mid-1;
            } else {
                return true;
            }
        }
        if (row == -1) return false;
        cout << "row: " << row << endl;
        int l = 0;
        int r = matrix[row].size()-1;
        while (l <= r) {
            int mid = (l + r) /2;
            if (matrix[row][mid] == target) {
                return true;
            } else if (matrix[row][mid] < target) {
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        return false;
    }
};
