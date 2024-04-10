class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n; i++){
            map<int,int> m1, m2;
            for(int j = 0; j < n; j++){
                m1[matrix[i][j]]++;
                m2[matrix[j][i]]++;
                if(m1[matrix[i][j]] > 1)return false;
                if(m2[matrix[j][i]] > 1)return false;
            }
        }
        return true;
    }
};