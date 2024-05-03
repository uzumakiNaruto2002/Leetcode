class Solution {
public:
    int minOperations(int k) {
        int sum = 1, ans = INT_MAX;
        for(int i = 1; i <= k; i++){
            int x = k;
            ans = min(ans, i - 1 + (x + i - 1)/i - 1);
        }
        return ans;
    }
};