class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        int n = nums.size(), centre;
        long long ans = 0;
        sort(nums.begin(), nums.end());
        centre = nums[n/2];
        if(centre == k)return 0;
        if(centre > k){
            for(int i = 0; i <= n/2; i++){
                if(k < nums[i]){
                    ans = ans + (long long)nums[i] - (long long)k;
                }
            }
        }
        else{
            for(int i = n - 1; i >= n/2; i--){
                if(k > nums[i]){
                    ans = ans - (long long)nums[i] + (long long)k;
                }
            }
        }
        return ans;
    }
};