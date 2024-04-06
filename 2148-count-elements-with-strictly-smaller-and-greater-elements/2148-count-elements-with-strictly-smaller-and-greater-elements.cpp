class Solution {
public:
    int countElements(vector<int>& nums) {
        int n = nums.size(), maxi = *max_element(nums.begin(), nums.end()), mini = *min_element(nums.begin(), nums.end()), ans = 0;
        for(auto i: nums){
            if(maxi > i && i > mini)ans++;
        }
        return ans;
    }
};