class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        int i = 0, j = 0, sum = 0, count = 0;
        vector<int> temp;
        temp.push_back(grid[0][0]);
        if(grid[0][0] > k)return 0;
        count++;
        for(int i = 1; i < m; i++){
            temp.push_back(temp.back() + grid[0][i]);
            if(temp.back() <= k)count++;
        }
        for(int i = 1; i < n; i++){
            int t = 0;
            for(int j = 0; j < m; j++){
                int x = temp[j] + grid[i][j] + t;
                if(x <= k)count++;
                t += grid[i][j];
                temp[j] += t;
                // cout<<x<<' ';
            }
        }
        return count;
    }
};