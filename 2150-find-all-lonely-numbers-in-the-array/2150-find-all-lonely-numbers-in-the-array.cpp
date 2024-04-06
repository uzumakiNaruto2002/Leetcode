class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        int n = nums.size();
        map<int, int> m;
        for(int i: nums)m[i]++;
        vector<int> ans;
        for(int i : nums){
            if(m[i] > 1 || m[i + 1] > 0 || m[i - 1] > 0){
                continue;
            }
            ans.push_back(i);
        }
        return ans;
    }
};