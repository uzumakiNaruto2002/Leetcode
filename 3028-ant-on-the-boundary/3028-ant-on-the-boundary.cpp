class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int n = nums.size(), count = nums[0], ans = 0;
        for(int i = 1; i < n; i++){
            count += nums[i];
            if(count == 0)ans++;
        }
        return ans;
    }
};