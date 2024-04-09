class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        int size = batteries.size();
        sort(batteries.rbegin(), batteries.rend());
        long long total = 0;
        for(auto i: batteries)total += i;
        for(int i = 0; i < size; i++){
            if(batteries[i] <= total/n){
                break;
            }
            total -= batteries[i];
            n--;
        }
        return total/n;
    }
};