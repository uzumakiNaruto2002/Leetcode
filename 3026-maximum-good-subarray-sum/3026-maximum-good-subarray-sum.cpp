class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int K) {
        int n = nums.size();
        long long k = K, ans = LLONG_MIN;
        vector<long long> prefix;
        long long a = nums[0];
        prefix.push_back(a);
        for(int i = 1; i < n; i++){
            prefix.push_back(a + nums[i]);
            a += nums[i];
        }
        a = nums[0];
        map<long long, long long> m;
        m[a] = 1;
        for(int i = 1; i < n; i++){
            long long x = nums[i];
            long long y = nums[i] - k;
            long long z = nums[i] + k;
            if(m[y] > 0){
                long long res = prefix[i] - (m[y] == 1 ? 0 : prefix[m[y] - 2]);
                // cout<<res<<"y ";
                ans = max(ans, res);
            }
            if(m[z] > 0){
                long long res = prefix[i] - (m[z] == 1 ? 0 : prefix[m[z] - 2]);
                // cout<<res<<"z ";
                ans = max(ans, res);
            }
            if(m[x] > 0){
                if(prefix[m[x] - 1] > prefix[i]){
                    m[x] = i + 1;
                }
            }
            else{
                m[x] = i + 1;
            }
        }
        if(ans == LLONG_MIN)return 0;
        return ans;
    }
};