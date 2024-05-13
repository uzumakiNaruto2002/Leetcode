class Solution {
public:
    string getSmallestString(string s, int k) {
        int n = s.size();
        string ans = "";
        for(int i = 0; i < n; i++){
            char t = s[i];
            for(char c = 'a'; c <= 'z'; c++){
                if(min(abs(t - c), abs(26 - t + c)) <= k){
                    k = k - min(abs(t - c), abs(26 - t + c));
                    ans += c;
                    break;
                }
            }
        }
        return ans;
    }
};