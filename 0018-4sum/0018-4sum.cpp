class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> s;
        vector<vector<int>> ans;
        long long n = nums.size();
        int a, b, c, d;
        sort(nums.begin(), nums.end());
        for (long long i = 0; i < n; i++) {
            a = nums[i];
            for (long long j = i + 1; j < n; j++) {
                b = nums[j];
                long long tar = (long long)((long long)target - (long long)a - (long long)b);
                long long k = j + 1, l = n - 1;
                while (k < l) {
                    if (nums[k] + nums[l] == tar) {
                        c = nums[k];
                        d = nums[l];
                        s.insert({a, b, c, d});
                        k++;
                        l--;
                    } else if (nums[k] + nums[l] < tar) {
                        k++;
                    } else {
                        l--;
                    }
                }
            }
        }
        for (auto i : s)
            ans.push_back(i);
        return ans;
    }
};