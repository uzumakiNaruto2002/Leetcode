class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        int a = 0, b = 0, ans = 0;
        for(int i = 0; i < bank[0].size(); i++){
            if(bank[0][i] == '1')a++;
        }
        for(int i = 1; i < n; i++){
            for(int j = 0; j < bank[i].size(); j++){
                if(bank[i][j] == '1')b++;
                if(j == bank[i].size() - 1){
                    ans = ans + a * b;
                    if(b != 0){
                        a = b;
                        b = 0;
                    }
                }
            }
        }
        return ans;
    }
};