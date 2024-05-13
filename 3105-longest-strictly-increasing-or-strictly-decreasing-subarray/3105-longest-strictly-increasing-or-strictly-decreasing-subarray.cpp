class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size(), ans = 1, i = 0, j = 1, k = 0;
        while(j < n){
            if(nums[j] > nums[k]){
                ans = max(ans, j - i + 1);
                j++;
                k++;
            }
            else{
                i = j;
                k++;
                j++;
            }
        }
        // ans = max(ans, j - i + 1);
        i = 0, j = 1, k = 0;
        while(j < n){
            if(nums[j] < nums[k]){
                ans = max(ans, j - i + 1);
                j++;
                k++;
            }
            else{
                i = j;
                k++;
                j++;
            }
        }
        // cout<<ans;
        // ans = max(ans, j - i + 1);
        return ans;
    }
};