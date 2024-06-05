
int solve(int prev, int n, int m, vector<vector<int>> &nums, vector<vector<int>> &dp, int index){
    if(index >= m)return 0;
    if(dp[index][prev + 1] != -1)return dp[index][prev + 1];
    int c = INT_MAX;
    for(int curr = 0; curr < 10; curr++){
        if(curr != prev){
            c = min(c, n - nums[index][curr] + solve(curr, n, m, nums, dp, index + 1)); 
        }
    }
    return dp[index][prev + 1] = c;
}

class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> nums;
        for(int j = 0; j < m; j++){
            vector<int> temp(10,0);
            for(int i = 0; i < n; i++){
                temp[grid[i][j]]++;
            }
            nums.push_back(temp);
        }
        vector<vector<int>> dp(m, vector<int>(11, -1));
        return solve(-1, n, m, nums, dp, 0);
    }
};