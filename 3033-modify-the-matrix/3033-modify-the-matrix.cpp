class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        for(int i = 0; i < m; i++){
            int maxi = INT_MIN;
            for(int j = 0; j < n; j++){
                if(matrix[j][i] > maxi){
                    maxi = matrix[j][i];
                }
            }
            for(int j = 0; j < n; j++){
                if(matrix[j][i] == -1){
                    matrix[j][i] = maxi;
                }
            }
        }
        return matrix;
    }
};