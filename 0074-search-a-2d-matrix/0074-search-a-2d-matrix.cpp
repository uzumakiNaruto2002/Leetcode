class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int s = 0, e = n*m - 1;
        while(s <= e){
            int mid = s + (e - s)/2;
            int row = (mid)/m;
            int col = mid % m;
            if(matrix[row][col] == target){
                return true;
            }
            else if(target > matrix[row][col]){
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }
        return false;
    }
};