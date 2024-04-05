class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n = nums.size(), zero = 0, one = 0, leftScore = 0, rightScore = 0, total = 0;
        for(auto i : nums){
            if(i == 0)zero++;
            if(i == 1)one++;
        }
        total = one;
        int dummy = one;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                dummy++;
            }
            else{
                dummy--;
            }
            total = max(total, dummy);
        }
        vector<int> ans;
        dummy = one;
        if(one == total)ans.push_back(0);
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                dummy++;
            }
            else{
                dummy--;
            }
            if(dummy == total)ans.push_back(i + 1);
        }
        return ans;
    }
};