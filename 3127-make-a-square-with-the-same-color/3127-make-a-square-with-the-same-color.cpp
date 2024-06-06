class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& grid) {
        int b = 0, w = 0, i = 0;
        // for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(i >= 0 && i <= 1 && j >= 0 && j <= 1){
                    if(grid[i][j] == 'B')b++;
                    else w++;
                    if(grid[i + 1][j] == 'B')b++;
                    else w++;
                }
            }
            // cout<<b<<' '<<w<<endl;
            if(b >= 3 || w >= 3)return true;
            b = 0, w = 0;
            for(int j = 0; j < 3; j++){
                if(i >= 0 && i <= 1 && j >= 1 && j <= 2){
                    if(grid[i][j] == 'B')b++;
                    else w++;
                    if(grid[i + 1][j] == 'B')b++;
                    else w++;
                }
            }
            if(b >= 3 || w >= 3)return true;
            b = 0, w = 0;
            for(int j = 0; j < 3; j++){
                if(j >= 0 && j <= 1){
                    if(grid[i + 1][j] == 'B')b++;
                    else w++;
                    if(grid[i + 2][j] == 'B')b++;
                    else w++;
                }
            }
            if(b >= 3 || w >= 3)return true;
            b = 0, w = 0;
            for(int j = 0; j < 3; j++){
                if(j >= 1 && j <= 2){
                    if(grid[i + 1][j] == 'B')b++;
                    else w++;
                    if(grid[i + 2][j] == 'B')b++;
                    else w++;
                }
            }
            if(b >= 3 || w >= 3)return true;
        // }
        return false;
    }
};