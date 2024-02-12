
void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis){
    int n = grid.size(), m = grid[0].size();
    if(i < 0 || i >= n || j < 0 || j >= m || vis[i][j] == 1 || grid[i][j] == 0)return;
    vis[i][j] = 1;
    dfs(i, j + 1, grid, vis);
    dfs(i, j - 1, grid, vis);
    dfs(i + 1, j, grid, vis);
    dfs(i - 1, j, grid, vis);
}

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++){
            if(vis[i][0] == 0 && grid[i][0] == 1){
                dfs(i, 0, grid, vis);
            }
            if(vis[i][m - 1] == 0 && grid[i][m - 1] == 1){
                dfs(i, m - 1, grid, vis);
            }
        }
        for(int i = 0; i < m; i++){
            if(vis[0][i] == 0 && grid[0][i] == 1){
                dfs(0, i, grid, vis);
            }
            if(vis[n - 1][i] == 0 && grid[n - 1][i] == 1){
                dfs(n - 1, i, grid, vis);
            }
        }
        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(vis[i][j] != 1 && grid[i][j] == 1)count++;
            }
        }
        return count;
    }
};