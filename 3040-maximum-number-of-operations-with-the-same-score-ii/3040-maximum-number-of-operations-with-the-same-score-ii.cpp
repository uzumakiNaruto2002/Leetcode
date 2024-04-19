
int solve(vector<int> &nums, int i, int j, int score, vector<vector<int>> &dp){
    int n = nums.size();
    if(i >= j){
        return 0;
    }
    if(dp[i][j] != -1)return dp[i][j];
    int ans = 0;
    if(nums[i] + nums[i + 1] == score){
        ans = max(ans, solve(nums, i + 2, j, score, dp) + 1);
    }
    if(nums[i] + nums[j] == score){
        ans = max(ans, solve(nums, i + 1, j - 1, score, dp) + 1);
    }
    if(nums[j] + nums[j - 1] == score){
        ans = max(ans, solve(nums, i, j - 2, score, dp) + 1);
    }
    return dp[i][j] = ans;
}

class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return 1 + max(solve(nums, 2, n - 1, nums[0] + nums[1], dp), max(solve(nums, 1, n - 2, nums[0] + nums[n - 1], dp), solve(nums, 0, n - 3, nums[n - 2] + nums[n - 1], dp)));
    }
};