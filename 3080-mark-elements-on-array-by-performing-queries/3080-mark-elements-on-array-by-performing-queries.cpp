class Solution {
public:
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), m = queries.size();
        vector<pair<int,int>> numInd;
        long long total = 0, sum = 0;
        for(int i = 0; i < n; i++){
            numInd.push_back({nums[i], i});
            total = total + (long long)(nums[i]);
        }
        sort(numInd.begin(), numInd.end());
        int j = 0;
        set<int> s;
        vector<long long> ans;
        for(int i = 0; i < m; i++){
            int index = queries[i][0], k = queries[i][1];
            if(s.find(index) == s.end()){
                s.insert(index);
                sum += nums[index];
            }
            for(int p = j; p < j + k && p < n; p++){
                if(s.find(numInd[p].second) == s.end()){
                    s.insert(numInd[p].second);
                    sum += nums[numInd[p].second];
                }
                else{
                    j++;
                }
            }
            ans.push_back(total - sum);
            j += k;
        }
        return ans;
    }
};