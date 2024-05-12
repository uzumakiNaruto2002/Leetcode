class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        long long i = 0, j = 1, k = 0;
        while(j < n){
            if(nums[k] == nums[j]){
                ans = ans + ((j - i) * (j - i + 1))/2;
                i = j;
                k = j;
                j++;
            }
            else{
                k++;
                j++;
            }
        }
        ans = ans + ((j - i) * (j - i + 1))/2;
        return ans;
    }
};