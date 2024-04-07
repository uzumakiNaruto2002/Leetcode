
bool comp(vector<int> &v1, vector<int> &v2) {
    if (v1[0] != v2[0])
        return v1[0] < v2[0];
    if (v1[1] != v2[1])
        return v1[1] < v2[1];
    if (v1[2] != v2[2])
        return v1[2] < v2[2];
    return v1[3] < v2[3];
}


class Solution {
public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        int n = grid.size(), m = grid[0].size(), dist = INT_MAX;
        queue<pair<pair<int,int>, int>> q;
        q.push({{start[0], start[1]}, 0});
        vector<vector<int>> temp, vis(n, vector<int>(m, 0));
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dis = q.front().second;
            q.pop();
            vis[row][col] = 1;
            if(temp.size() > k){
                dist = dis;
            }
            if(dis <= dist){
                if(grid[row][col] != 0 && grid[row][col] >= pricing[0] && grid[row][col] <= pricing[1] && grid[row][col] != 1){
                    temp.push_back({dis, grid[row][col], row, col});
                }
            }
            else{
                break;
            }
            for(int i = 0; i < 4; i++){
                int r = row + dr[i];
                int c = col + dc[i];
                if(r < n && r >= 0 && c < m && c >= 0 && grid[r][c] != 0 && vis[r][c] == 0){
                    vis[r][c] = 1;
                    q.push({{r, c}, dis + 1});
                }
            }
        }
        sort(temp.begin(), temp.end(), comp);
        vector<vector<int>> ans;
        for(int i = 0; i < k && i < temp.size(); i++){
            ans.push_back({temp[i][2], temp[i][3]});
        }
        return ans;
    }
    
};