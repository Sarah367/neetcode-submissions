class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int top = 0;
        int bottom = matrix.size()-1;

        int row = -1;

        while (top <= bottom) {
            int mid = (top + bottom)/2;

            if (matrix[mid][0] <= target) {
                row = mid;
                top = mid + 1;
            } else {
                bottom = mid-1;
            }

        }
        cout << "row: " << row << endl;
        if (row == -1) {
            return false;
        }
        int left = 0;
        int right = matrix[row].size()-1;
        while (left <= right) {
            int mid = (left+right)/2;
            if (matrix[row][mid] == target) {
                return true;
            } else if (matrix[row][mid] < target) {
                left = mid+1;
            } else {
                right=mid-1;
            }
        }

        return false;
    }
};
