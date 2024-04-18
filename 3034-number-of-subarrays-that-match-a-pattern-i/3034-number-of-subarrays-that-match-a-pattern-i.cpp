class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int m = pattern.size(), n = nums.size();
        int ans = 0;
        vector<int> temp;
        for(int i = 0; i < m + 1; i++){
            temp.push_back(nums[i]);
        }
        for(int i = m; i < n; i++){
            int t = 0;
            if(i > m){
                reverse(temp.begin(), temp.end());
                temp.pop_back();
                reverse(temp.begin(), temp.end());
                temp.push_back(nums[i]);
            }
            for(int j = 0; j < m; j++){
                if((pattern[j] == 1 && temp[j + 1] > temp[j]) || (pattern[j] == 0 && temp[j + 1] == temp[j]) || (pattern[j] == -1 && temp[j + 1] < temp[j])){
                    continue;
                }
                else{
                    t = 1;
                    break;
                }
            }
            if(t == 0)ans++;
        }
        return ans;
    }
};