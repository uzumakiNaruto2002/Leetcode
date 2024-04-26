class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n = happiness.size(), t = k - 1;
        long long ans = 0;
        sort(happiness.rbegin(), happiness.rend());
        for(int i = k - 1; i >= 0; i--){
            long long x = (long long)(happiness[i] - t);
            if(x < 0)x = 0;
            t--;
            ans += x;
        }
        return ans;
    }
};