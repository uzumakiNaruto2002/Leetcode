class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int row = -1, s = 0, e = n - 1, col = -1;
        while(s <= e){
            int mid = s + (e - s)/2;
            if(target >= matrix[mid][0]){
                row = mid;
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }
        if(row == -1)return false;
        s = 0, e = m - 1;
        while(s <= e){
            int mid = s + (e - s)/2;
            if(target == matrix[row][mid]){
                return true;
            }
            else if(target > matrix[row][mid]){
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }
        return false;
    }
};