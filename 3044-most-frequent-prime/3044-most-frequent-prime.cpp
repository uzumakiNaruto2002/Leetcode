
// int MAX = 1e7;
// vector<int> prime(MAX, 1);
// void findPrime(int MAX, vector<int> &prime){
//     for(int p = 2; p*p < MAX; p++){
//         if(prime[p] == 1){
//             for(int i = p * p; i < MAX; i += p){
//                 prime[i] = 0;
//             }
//         }
//     }
// }

class Solution {
public:

    void findPrime(int MAX, vector<int> &prime) {
        for(int p = 2; p*p < MAX; p++){
            if(prime[p] == 1){
                for(int i = p * p; i < MAX; i += p){
                    prime[i] = 0;
                }
            }
        }
    }
    int mostFrequentPrime(vector<vector<int>>& mat) {
        static vector<int> prime;
        if (prime.size() == 0) {
            int MAX = 1e7;
            prime.resize(MAX, 1);
            findPrime(MAX, prime);
        }
        int n = mat.size(), m = mat[0].size();
        int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};
        unordered_map<int, int> freq;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                for(int k = 0; k < 8; k++){
                    int x = dr[k], y = dc[k], num = 0;;
                    queue<pair<int,int>> q;
                    q.push({i, j});
                    while(!q.empty()){
                        int row = q.front().first;
                        int col = q.front().second;
                        q.pop();
                        num = num * 10 + mat[row][col];
                        if(prime[num] == 1 && num > 10){
                            freq[num]++;
                        }
                        row = row + x, col = col + y;
                        if(row < n && row >= 0 && col < m && col >= 0){
                            q.push({row, col});
                        }
                    }
                }
            }
        }
        int maxi = 0, ans = -1;
        for(auto i: freq){
            maxi = max(maxi, i.second);
            cout<<i.first<<' '<<i.second<<endl;
        }
        for(auto i: freq){
            if(i.second == maxi){
                ans = max(ans, i.first);
            }
        }
        return ans;
    }
};