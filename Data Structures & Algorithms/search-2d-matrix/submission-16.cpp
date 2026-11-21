class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left = 0;
        int right = matrix.size()-1;
        cout << matrix.size() << endl;
        int row = -1;
        int mid = 0;
        while (left <= right) {
            mid = (right+left)/2;

            if (matrix[mid][0] == target) {
                return true;
            } else if (matrix[mid][0] < target) {
                left = mid+1;
            } else if (matrix[mid][0] > target) {
                right = mid-1;
            }
        }
        if (right < 0) return false;

        cout << right << endl;

        int l = 0;
        int r = matrix[r].size()-1;
        int m = 0;
        while (l <= r) {
            m = (r+l)/2;

            if (matrix[right][m] == target) {
                return true;
            } else if (matrix[right][m] < target) {
                l = m+1;
            } else {
                r = m-1;
            }
        }

        return false;


    }
};
