class Solution {
public:
    int minimumPushes(string word) {
        // map<char, int, greater<int>> m;
        vector<int> temp(26, 0);
        for(auto i: word){
            temp[i - 'a']++;
        }
        sort(temp.rbegin(), temp.rend());
        int ans = 0, k = 0;
        for(auto i: temp){
            if(k < 8){
                ans = ans + i * 1;
            }
            else if(k < 16){
                ans = ans + i * 2;
            }
            else if(k < 24){
                ans = ans + i * 3;
            }
            else{
                ans = ans + i * 4;
            }
            k++;
        }
        return ans;
    }
};