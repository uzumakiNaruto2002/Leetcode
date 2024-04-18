
vector<int> Z_Function(string s){
    int n = s.size(), l = 0, r = 0;
    vector<int> z(n, 0);
    for(int i = 1; i < n; i++){
        if(i < r){
            z[i] = min(z[i - l], r - i);
        }
        while(i + z[i] < n && s[i + z[i]] == s[z[i]]){
            z[i]++;
            l = i;
            r = i + z[i];
        }
        // if(i + z[i] > r){
        //     l = i;
        //     r = i + z[i];
        // }
    }
    return z;
}

class Solution {
public:
    int minimumTimeToInitialState(string word, int k) {
        int n = word.size(), count = 0;
        vector<int> temp = Z_Function(word);
        for(int i = 1; i < n; i++){
            if(i % k == 0 && temp[i] == n - i){
                count = (n - temp[i])/k;
                break;
            }
            if(i == n - 1){
                count = (n + k - 1)/k;
            }
        }
        return count;
    }
};