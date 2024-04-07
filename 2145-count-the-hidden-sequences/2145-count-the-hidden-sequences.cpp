class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int n = differences.size();
        int x = 0;
        vector<long long> temp;
        temp.push_back(x);
        for(int i = 0; i < n; i++){
            int y = (long long)differences[i] + temp.back();
            temp.push_back(y);
        }
        // for(auto i: temp)cout<<i<<' ';
        long long t1 = LLONG_MIN, t2 = LLONG_MAX;
        for(int i = 0; i < temp.size(); i++){
            long long y = (long long)lower - temp[i];
            t1 = max(t1, y);
        }
        for(int i = 0; i < temp.size(); i++){
            long long y = (long long)upper - temp[i];
            t2 = min(t2, y);
        }
        if(t2 - t1 + 1 < 0)return 0;
        return t2 - t1 + 1;
    }
};