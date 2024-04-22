
int solve(vector<int> &nums, int index, int inc, vector<vector<int>> &dp){
    int n = nums.size();
    if(index >= n)return 0;
    int ans = 0;
    if(dp[index][inc] != -1)return dp[index][inc];
    if(inc == 1){
        if(nums[index] == nums[index - 1] + 1){
            ans = max(ans, 1 + solve(nums, index + 1, 1, dp));
        }
        else if(nums[index] == nums[index - 1] + 2){
            ans = max(ans, 1 + solve(nums, index + 1, 0, dp));
        }
        else if(nums[index] == nums[index - 1]){
            ans = max(ans, solve(nums, index + 1, 1, dp));
        }
    }
    else{
        if(nums[index] == nums[index - 1]){
            ans = max(ans, 1 + solve(nums, index + 1, 1, dp));
        }
        else if(nums[index] == nums[index - 1] + 1){
            ans = max(ans, 1 + solve(nums, index + 1, 0, dp));
        }
    }
    return dp[index][inc] = ans;
}

class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        int n = nums.size(), res = 1;
        sort(nums.begin(), nums.end());
        vector<vector<int>> dp(n + 1, vector<int> (2, -1));
        for(int i = 1; i < n; i++){
            res = max(res, 1 + max(solve(nums, i, 0, dp), solve(nums, i, 1, dp)));
        }
        return res;
    }
};