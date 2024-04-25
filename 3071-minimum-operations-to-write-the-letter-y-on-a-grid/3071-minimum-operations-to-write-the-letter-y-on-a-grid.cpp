class Solution {
public:
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        int n = grid.size();
        map<pair<int, int>, int> m;
        for(int i = 0; i <= n/2; i++){
            m[{i, i}] = 1;
        }
        for(int i = 0; i < n/2; i++){
            m[{i, n - i - 1}] = 1;
        }
        for(int i = n/2 + 1; i < n; i++){
            m[{i, n/2}]= 1;
        }
        int k = 0;
        int zeroy = 0, oney = 0, twoy = 0, zero = 0, one = 0, two = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(m[{i, j}] == 1){
                    if(grid[i][j] == 0)zeroy++;
                    else if(grid[i][j] == 1)oney++;
                    else if(grid[i][j] == 2)twoy++;
                    k++;
                }
                else{
                    if(grid[i][j] == 0)zero++;
                    else if(grid[i][j] == 1)one++;
                    else if(grid[i][j] == 2)two++;
                }
            }
        }
        // cout<<zeroy<<' '<<oney<<' '<<twoy<<endl;
        // cout<<zero<<' '<<one<<' '<<two<<endl;
        return min(k - zeroy + zero + min(one, two), min(k - oney + one + min(zero, two), k - twoy + two + min(one, zero)));
    }
};