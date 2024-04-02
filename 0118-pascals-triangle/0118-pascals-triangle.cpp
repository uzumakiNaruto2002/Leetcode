class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        ans.push_back({1});
        if(n == 1)return ans;
        for(int i = 2; i <= n; i++){
            vector<int> temp(i);
            temp[0] = 1;
            temp[i - 1] = 1;
            for(int j = 1; j < i - 1; j++){
                temp[j] = ans.back()[j - 1] + ans.back()[j];
            }
            ans.push_back(temp);
        }
        return ans;
    }
};