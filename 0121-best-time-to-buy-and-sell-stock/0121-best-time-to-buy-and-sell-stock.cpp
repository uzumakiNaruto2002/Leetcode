class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int profit = 0, n = nums.size(), buy = nums[0];
        for(int i = 1; i < n; i++){
            profit = max(profit, nums[i] - buy);
            buy = min(buy, nums[i]);
        }
        return profit;
    }
};