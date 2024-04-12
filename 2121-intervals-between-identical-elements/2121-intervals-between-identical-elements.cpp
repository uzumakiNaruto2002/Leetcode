class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        map<int, vector<int>> m;
        map<long long, long long> m1;
        int n = arr.size();
        for(int i = 0; i < n; i++){
            if(m.find(arr[i]) != m.end()){
                m1[arr[i]] = (long long)m1[arr[i]] + (long long)i - (long long)m[arr[i]][0]; 
            }
            m[arr[i]].push_back(i);
        }
        // for(auto i: m1){
        //     cout<<i.first<<' '<<i.second<<endl;
        // }
        vector<long long> ans(n, 0);
        for(auto i: m){
            if(i.second.size() == 1){
                ans[i.second[0]] = 0;
            }
            else{
                ans[i.second[0]] = m1[arr[i.second[0]]];
                long long left = 0, right = i.second.size() - 2;
                for(int j = 1; j < i.second.size(); j++){
                    ans[i.second[j]] = ans[i.second[j - 1]] + ((left - right) * (long long)(abs(i.second[j] - i.second[j - 1])));
                    left++, right--;
                }
            }
        }
        return ans;
    }
};