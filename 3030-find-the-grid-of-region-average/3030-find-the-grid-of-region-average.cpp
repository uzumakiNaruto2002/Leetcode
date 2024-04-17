class Solution {
public:
    vector<vector<int>> resultGrid(vector<vector<int>>& image, int K) {
        int n = image.size(), m = image[0].size();
        vector<vector<pair<int, int>>> temp(n, vector<pair<int,int>> (m, {0, 0}));
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        for(int i = 0; i < n - 2; i++){
            for(int j = 0; j < m - 2; j++){
                int t = 0, sum = 0;
                for(int k = i; k <= i + 2; k++){
                    for(int l = j; l <= j + 2; l++){
                        for(int p = 0; p < 4; p++){
                            int r = k + dr[p];
                            int c = l + dc[p];
                            if(r >= i && r <= i + 2 && c >= j && c <= j + 2){
                                if(abs(image[k][l] - image[r][c]) > K){
                                    t = 1;
                                    break;
                                }
                            }
                        }
                        if(t == 1)break;
                        sum += image[k][l];
                    }
                    if(t == 1)break;
                }
                if(t == 0){
                    int avg = sum/9;
                    for(int k = i; k <= i + 2; k++){
                        for(int l = j; l <= j + 2; l++){
                            temp[k][l] = {temp[k][l].first + avg, temp[k][l].second + 1};
                        }
                    }
                }
            }
        }
        // for(auto i: temp){
        //     for(auto j: i){
        //         cout<<j.first<<','<<j.second<<" ";
        //     }
        //     cout<<endl;
        // }
        vector<vector<int>> ans = image;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(temp[i][j].second == 0){
                    continue;
                }
                else{
                    ans[i][j] = temp[i][j].first/temp[i][j].second;
                }
            }
        }
        return ans;
    }
};