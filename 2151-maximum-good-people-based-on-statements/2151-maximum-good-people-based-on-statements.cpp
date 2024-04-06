
bool right(string store, vector<vector<int>>& statements){
    int n = statements.size();
    for(int i = 0; i < n; i++){
        if(store[i] == '1'){
            for(int j = 0; j < n; j++){
                if(statements[i][j] != 2){
                    if(statements[i][j] != store[j] - '0')return 0;
                }
            }
        }
    }
    return 1;
}

void countMax(vector<vector<int>>& statements, int index, string store, int count, int &ans){
    if(index == statements.size()){
        if(right(store, statements)){
            ans = max(ans, count);
        }
        return;
    }
    store.push_back('1');
    countMax(statements, index + 1, store, count + 1, ans);
    store.back() = '0';
    countMax(statements, index + 1, store, count, ans);
}

class Solution {
public:
    int maximumGood(vector<vector<int>>& statements) {
        int n = statements.size(), ans = 0, count = 0;
        string store = "";
        countMax(statements, 0, store, count, ans);
        return ans;
    }
};