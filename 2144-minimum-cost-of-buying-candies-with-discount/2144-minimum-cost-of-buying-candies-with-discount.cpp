class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size(), ans = 0, k = 0;
        sort(cost.begin(), cost.end());
        for(int i = n - 1; i >= 0; i--){
            if(k != 2){
                k++;
                ans += cost[i];
            }
            else{
                k = 0;
            }
        }
        return ans;
    }
};