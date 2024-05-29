class Solution {
public:
    int scoreOfString(string s) {
        int n = s.size(), ans = 0;
        for(int i = 0; i < n - 1; i++){
            int x = abs(s[i + 1] - s[i]);
            ans += x;
        }
        return ans;
    }
};