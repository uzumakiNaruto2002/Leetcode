
int mod = 1e9 + 7;

class Solution {
public:
    int numberOfWays(string corridor) {
        int n = corridor.size(), ans = 1;
        int count = 0, total = 0, t = 0;
        vector<int> temp;
        for(int i = 0; i < n; i++){
            if(corridor[i] == 'S'){
                total++;
                count++;
                if(count == 3){
                    count = 1;
                    temp.push_back(t);
                    t = 0;
                }
            }
            if(count == 2){
                t++;
            }
        }
        if(total % 2 == 1 || total == 0)return 0;
        for(auto i: temp){
            ans = ((long long)ans * (long long)i) % mod;
        }
        return ans;
    }
};