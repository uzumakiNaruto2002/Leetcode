class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        unordered_map<int, int> m;
        for(auto i: nums)m[i]++;
        int ans = 1, count = 0;
        for(int i = 0; i < n; i++){
            long long x = nums[i], left = 0;
            if(x == 1){
                if(m[x] % 2 == 1)ans = max(ans, m[x]);
                else ans = max(ans, m[x] - 1);
                continue;
            }
            while(1){
                if(m[x] > 1){
                    left++;
                    if(x > 1e6){
                        count = 2 * left - 1;
                        break;
                    }
                    x = x * x;
                }
                else if(m[x] == 0){
                    count = 2 * left - 1;
                    break;
                }
                else if(m[x] == 1){
                    count = 2 * left + 1;
                    break;
                }
            }
            ans = max(ans, count);
        }
        return ans;
    }
};