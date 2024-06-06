class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        map<int, int> row, col;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    row[i]++;
                }
            }
        }
        for(int j = 0; j < m; j++){
            for(int i = 0; i < n; i++){
                if(grid[i][j] == 1){
                    col[j]++;
                }
            }
        }
        long long ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    ans = ans + (long long)(row[i] - 1) * (long long)(col[j] - 1);
                }
            }
        }
        return ans;
    }
};