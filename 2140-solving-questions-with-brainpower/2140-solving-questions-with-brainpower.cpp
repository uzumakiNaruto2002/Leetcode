
long long solve(int index, vector<vector<int>> &temp, vector<long long> &dp){
    if(index >= temp.size()){
        return 0;
    }
    if(dp[index] != -1)return dp[index];
    long long inc = temp[index][0] + solve(index + 1 + temp[index][1], temp, dp);
    long long exc  = solve(index + 1, temp, dp);
    return dp[index] = max(inc, exc);
}

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> dp(questions.size(), -1);
        return solve(0, questions, dp);
    }
};