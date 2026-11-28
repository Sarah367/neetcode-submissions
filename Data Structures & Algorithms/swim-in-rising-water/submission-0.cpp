class Solution {
   public:
    int swimInWater(vector<vector<int>>& grid) {
        // grid

        // {tallest square so far, row, col}
        // max(tallest so far, neighbor's height)

        unordered_map<int, int> shortest;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            minHeap;
        // {tallest square so far, {row , col} };
        minHeap.push({grid[0][0], {0, 0}});
        int rowFinal = grid.size();
        int colFinal = grid[0].size();
        int maxSquare = 0;
        while (!minHeap.empty()) {
            pair<int, pair<int, int>> p = minHeap.top();

            minHeap.pop();

            int weight = p.first;
            int row = p.second.first;
            int col = p.second.second;
            if (grid[row][col] == grid[rowFinal - 1][colFinal - 1]) {
                return p.first;
            }
            if (shortest.count(grid[row][col]) > 0) {
                continue;
            }
            shortest[grid[row][col]] = weight;

            vector<pair<int, int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
            for (pair<int, int> dir : directions) {
                int r = row + dir.first;
                int c = col + dir.second;
                if (r < 0 || r >= grid.size() || c >= grid[row].size() || c < 0) continue;

                if (shortest.count(grid[r][c]) == 0) {
                    minHeap.push({max(weight, grid[r][c]), {r, c}});
                }
            }
        }
        return maxSquare;
    }
};
